// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TeamPawn.generated.h"

UCLASS(Blueprintable, Abstract, BlueprintType)
class HEISTGAMECLONE_API ATeamPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATeamPawn();

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetActorEyesViewPoint_Blueprint(FVector& Location, FRotator& Rotation) const;
	virtual void GetActorEyesViewPoint_Blueprint_Implementation(FVector& Location, FRotator& Rotation) const;

	virtual void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override;

};
