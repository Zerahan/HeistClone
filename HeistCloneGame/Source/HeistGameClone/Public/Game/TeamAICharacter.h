// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TeamAICharacter.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract)
class HEISTGAMECLONE_API ATeamAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATeamAICharacter();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetActorEyesViewPoint_Blueprint(FVector& Location, FRotator& Rotation) const;
	virtual void GetActorEyesViewPoint_Blueprint_Implementation(FVector& Location, FRotator& Rotation) const;

	virtual void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override;

};
