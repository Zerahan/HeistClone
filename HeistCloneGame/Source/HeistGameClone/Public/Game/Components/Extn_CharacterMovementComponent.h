// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Extn_CharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class HEISTGAMECLONE_API UExtn_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	/** The maximum ground speed when sprinting. Also determines maximum lateral speed when falling. */
	UPROPERTY(Category = "Character Movement: Sprinting", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"))
	float MaxSprintSpeed;

	/** The maximum ground speed when sprinting and crouched. */
	UPROPERTY(Category = "Character Movement: Sprinting", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"))
	float MaxSprintSpeedCrouched;
};
