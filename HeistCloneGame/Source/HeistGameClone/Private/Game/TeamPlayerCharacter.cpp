// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/TeamPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ATeamPlayerCharacter::ATeamPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseCameraPitchRate = 45.f;
	BaseCameraYawRate = 45.f;

	ControlPitch = 0;
	ControlYaw = 0;

	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	GetCapsuleComponent()->InitCapsuleSize(34.f, 88.f);

	GetCharacterMovement()->MaxWalkSpeed = 500.f;

	auto* DefaultCharacterMesh = GetMesh();
	if (DefaultCharacterMesh) {
		DefaultCharacterMesh->SetOnlyOwnerSee(false);
		DefaultCharacterMesh->SetOwnerNoSee(true);
		DefaultCharacterMesh->SetRelativeRotation(FRotator(0,-90,0));
		DefaultCharacterMesh->SetRelativeLocation(FVector(0, 0, -1 * GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));
	}

	Mesh_FirstPerson = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	if (Mesh_FirstPerson) {
		Mesh_FirstPerson->SetupAttachment(GetCapsuleComponent());
		Mesh_FirstPerson->SetOnlyOwnerSee(true);
		Mesh_FirstPerson->SetOwnerNoSee(false);
		Mesh_FirstPerson->bRenderInMainPass = false;
		Mesh_FirstPerson->CastShadow = true;
		Mesh_FirstPerson->bCastDynamicShadow = true;
		Mesh_FirstPerson->SetCollisionProfileName("NoCollision", false);
		Mesh_FirstPerson->SetRelativeRotation(FRotator(0, -90, 0));
		Mesh_FirstPerson->SetRelativeLocation(FVector(0, 0, -1 * GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));
		//Mesh_FirstPerson->SetRelativeScale3D(FVector(1.05f, 1.05f, 1.05f));
	}

	// For the ability to switch to third person.
	CameraAttachmentComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	if (CameraAttachmentComponent) {
		CameraAttachmentComponent->SetupAttachment(Mesh_FirstPerson);
		//CameraAttachmentComponent->SetupAttachment(Mesh_FirstPerson, "head");
		//CameraAttachmentComponent->SetRelativeLocation(FVector(-5.f, 0.f, 0.f));
		//CameraAttachmentComponent->SetRelativeRotation(FRotator(0.f, 70.f, -90.f));
		CameraAttachmentComponent->SetRelativeLocation(FVector(0, 0, 164));
		CameraAttachmentComponent->SetRelativeRotation(FRotator(0, 0, -90));
		CameraAttachmentComponent->TargetArmLength = 0;
		CameraAttachmentComponent->bDoCollisionTest = false;
		CameraAttachmentComponent->bUsePawnControlRotation = true;
	}
	
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	if (FirstPersonCamera) {
		FirstPersonCamera->SetupAttachment(CameraAttachmentComponent);
		FirstPersonCamera->SetRelativeLocation(FVector(0, 0, 0));
	}
}

// Called when the game starts or when spawned
void ATeamPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATeamPlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATeamPlayerCharacter, ControlPitch);
	DOREPLIFETIME(ATeamPlayerCharacter, ControlYaw);
}

// Called every frame
void ATeamPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority() || IsLocallyControlled()) {
		ControlYaw = GetControlRotation().Yaw;
		if (ControlYaw > 180) ControlYaw = ControlYaw - 360;
		ControlPitch = GetControlRotation().Pitch;
		if (ControlPitch > 90) ControlPitch = ControlPitch - 360;
	}
}

// Called to bind functionality to input
void ATeamPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Basic controls
	PlayerInputComponent->BindAxis("MoveForward", this, &ATeamPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATeamPlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("CameraRight", this, &ATeamPlayerCharacter::CameraRight);
	PlayerInputComponent->BindAxis("CameraUp", this, &ATeamPlayerCharacter::CameraUp);
	PlayerInputComponent->BindAxis("CameraRightRate", this, &ATeamPlayerCharacter::CameraRightRate);
	PlayerInputComponent->BindAxis("CameraUpRate", this, &ATeamPlayerCharacter::CameraUpRate);

	// Basic actions
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ATeamPlayerCharacter::ActionStartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ATeamPlayerCharacter::ActionStopCrouch);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ATeamPlayerCharacter::ActionStartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ATeamPlayerCharacter::ActionStopSprint);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATeamPlayerCharacter::ActionStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ATeamPlayerCharacter::ActionStopJump);

	// Game-specific actions
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &ATeamPlayerCharacter::ActionStartUse);
	PlayerInputComponent->BindAction("Use", IE_Released, this, &ATeamPlayerCharacter::ActionStopUse);

	PlayerInputComponent->BindAction("PrimaryAction", IE_Pressed, this, &ATeamPlayerCharacter::ActionStartPrimary);
	PlayerInputComponent->BindAction("PrimaryAction", IE_Released, this, &ATeamPlayerCharacter::ActionStopPrimary);

	PlayerInputComponent->BindAction("SecondaryAction", IE_Pressed, this, &ATeamPlayerCharacter::ActionStartSecondary);
	PlayerInputComponent->BindAction("SecondaryAction", IE_Released, this, &ATeamPlayerCharacter::ActionStopSecondary);

	PlayerInputComponent->BindAction("TertiaryAction", IE_Pressed, this, &ATeamPlayerCharacter::ActionStartTertiary);
	PlayerInputComponent->BindAction("TertiaryAction", IE_Released, this, &ATeamPlayerCharacter::ActionStopTertiary);

}

void ATeamPlayerCharacter::AddControllerPitchInput(float Val)
{
	Super::AddControllerPitchInput(Val);
}

void ATeamPlayerCharacter::AddControllerYawInput(float Val)
{
	Super::AddControllerYawInput(Val);
}

FRotator ATeamPlayerCharacter::GetReplicatedControlRotation() const
{
	return FRotator(ControlPitch, ControlYaw, 0);
}

void ATeamPlayerCharacter::MoveForward_Implementation(float AxisValue)
{
	if (AxisValue != 0) {
		AddMovementInput(GetActorForwardVector(), AxisValue);
	}
}

void ATeamPlayerCharacter::MoveRight_Implementation(float AxisValue)
{
	if (AxisValue != 0) {
		AddMovementInput(GetActorRightVector(), AxisValue);
	}
}

void ATeamPlayerCharacter::CameraRight_Implementation(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void ATeamPlayerCharacter::CameraUp_Implementation(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void ATeamPlayerCharacter::CameraRightRate_Implementation(float AxisValue)
{
	AddControllerYawInput(AxisValue * BaseCameraYawRate * GetWorld()->GetDeltaSeconds());
}

void ATeamPlayerCharacter::CameraUpRate_Implementation(float AxisValue)
{
	AddControllerYawInput(AxisValue * BaseCameraPitchRate * GetWorld()->GetDeltaSeconds());
}

void ATeamPlayerCharacter::ActionStartCrouch_Implementation()
{
	Crouch();
}

void ATeamPlayerCharacter::ActionStopCrouch_Implementation()
{
	UnCrouch();
}

void ATeamPlayerCharacter::ActionStartJump_Implementation()
{
	Jump();
}

void ATeamPlayerCharacter::ActionStopJump_Implementation()
{
	StopJumping();
}

void ATeamPlayerCharacter::ActionStartSprint_Implementation()
{
}

void ATeamPlayerCharacter::ActionStopSprint_Implementation()
{
}

void ATeamPlayerCharacter::ActionStartUse_Implementation()
{
}

void ATeamPlayerCharacter::ActionStopUse_Implementation()
{
}

bool ATeamPlayerCharacter::GetCanPrimaryAction_Implementation()
{
	return false;
}

void ATeamPlayerCharacter::ActionStartPrimary_Implementation()
{
}

void ATeamPlayerCharacter::ActionStopPrimary_Implementation()
{
}

bool ATeamPlayerCharacter::GetCanSecondaryAction_Implementation()
{
	return false;
}

void ATeamPlayerCharacter::ActionStartSecondary_Implementation()
{
}

void ATeamPlayerCharacter::ActionStopSecondary_Implementation()
{
}

bool ATeamPlayerCharacter::GetCanTertiaryAction_Implementation()
{
	return false;
}

void ATeamPlayerCharacter::ActionStartTertiary_Implementation()
{
}

void ATeamPlayerCharacter::ActionStopTertiary_Implementation()
{
}
