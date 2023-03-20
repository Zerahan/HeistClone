// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/Zone_Basic.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"

#ifndef ECC_INTERACT
#define ECC_INTERACT		ECC_GameTraceChannel3
#endif

// Sets default values
AZone_Basic::AZone_Basic()
	:Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	//RootComponent = CollisionComponent;
	//CollisionComponent = CreateOptionalDefaultSubobject<CollisionComponentClass, UShapeComponent>(TEXT("CollisionComponent"));
	CollisionComponent = CreateDefaultSubobject<UShapeComponent>(TEXT("CollisionComponent"));
	if (CollisionComponent) {
		RootComponent = CollisionComponent;
		CollisionComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
		CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	}
}

#if WITH_EDITOR
void AZone_Basic::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property == NULL) return;
	FName PropertyName = PropertyChangedEvent.Property->GetFName();
	if (PropertyName == NAME_None) return;
	if (!IsValid(CollisionComponent)) return;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZone_Basic, bBlockAll)) {
		CollisionComponent->SetCollisionResponseToAllChannels((bBlockAll ? ECollisionResponse::ECR_Block : ECollisionResponse::ECR_Ignore));
		CollisionComponent->SetCollisionEnabled(bBlockAll ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::QueryOnly);
		CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, (bBlockVisibility ? ECollisionResponse::ECR_Block : ECollisionResponse::ECR_Ignore));
		CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, (bBlockPathing ? ECollisionResponse::ECR_Block : ECollisionResponse::ECR_Ignore));
		CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_INTERACT, (bBlockInteraction ? ECollisionResponse::ECR_Block : ECollisionResponse::ECR_Ignore));
	}
	
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZone_Basic, bBlockVisibility)){
		CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, (bBlockVisibility ? ECollisionResponse::ECR_Block : ECollisionResponse::ECR_Ignore));
	}
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZone_Basic, bBlockPathing)) {
		CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, (bBlockPathing ? ECollisionResponse::ECR_Block : ECollisionResponse::ECR_Ignore));
	}
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZone_Basic, bBlockInteraction)) {
		CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_INTERACT, (bBlockInteraction ? ECollisionResponse::ECR_Block : ECollisionResponse::ECR_Ignore));
	}
}
#endif

// Called when the game starts or when spawned
void AZone_Basic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZone_Basic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

inline UShapeComponent* AZone_Basic::GetCollisionComponent() const {
	return CollisionComponent;
}

