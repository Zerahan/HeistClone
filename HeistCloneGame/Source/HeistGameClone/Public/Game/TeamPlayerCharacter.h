// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TeamPlayerCharacter.generated.h"

class USkeletalMeshComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS(Blueprintable, BlueprintType, Abstract)
class HEISTGAMECLONE_API ATeamPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh_FirstPerson;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraAttachmentComponent;

public:
	// Sets default values for this character's properties
	ATeamPlayerCharacter();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default|Input")
	float BaseCameraPitchRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default|Input")
	float BaseCameraYawRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(Replicated)
	float ControlPitch;
	
	UPROPERTY(Replicated)
	float ControlYaw;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void AddControllerPitchInput(float Val) override;
	virtual void AddControllerYawInput(float Val) override;

	UFUNCTION(BlueprintCallable)
	FRotator GetReplicatedControlRotation() const;

	// Basic controls
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void MoveForward(float AxisValue);
	virtual void MoveForward_Implementation(float AxisValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void MoveRight(float AxisValue);
	virtual void MoveRight_Implementation(float AxisValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void CameraRight(float AxisValue);
	virtual void CameraRight_Implementation(float AxisValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void CameraUp(float AxisValue);
	virtual void CameraUp_Implementation(float AxisValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void CameraRightRate(float AxisValue);
	virtual void CameraRightRate_Implementation(float AxisValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void CameraUpRate(float AxisValue);
	virtual void CameraUpRate_Implementation(float AxisValue);

	// Basic actions
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStartCrouch();
	virtual void ActionStartCrouch_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStopCrouch();
	virtual void ActionStopCrouch_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStartJump();
	virtual void ActionStartJump_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStopJump();
	virtual void ActionStopJump_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStartSprint();
	virtual void ActionStartSprint_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStopSprint();
	virtual void ActionStopSprint_Implementation();

	// Game-specific actions
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStartUse();
	virtual void ActionStartUse_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStopUse();
	virtual void ActionStopUse_Implementation();

	// Equipment Actions
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input|Validation")
	bool GetCanPrimaryAction() const;
	virtual bool GetCanPrimaryAction_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStartPrimary();
	virtual void ActionStartPrimary_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStopPrimary();
	virtual void ActionStopPrimary_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input|Validation")
	bool GetCanSecondaryAction() const;
	virtual bool GetCanSecondaryAction_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStartSecondary();
	virtual void ActionStartSecondary_Implementation();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStopSecondary();
	virtual void ActionStopSecondary_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input|Validation")
	bool GetCanTertiaryAction() const;
	virtual bool GetCanTertiaryAction_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStartTertiary();
	virtual void ActionStartTertiary_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default|Input")
	void ActionStopTertiary();
	virtual void ActionStopTertiary_Implementation();

};
