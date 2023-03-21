// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/TeamAICharacter.h"

// Sets default values
ATeamAICharacter::ATeamAICharacter()
	: Super()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATeamAICharacter::GetActorEyesViewPoint_Blueprint_Implementation(FVector& Location, FRotator& Rotation) const
{
	Location = GetPawnViewLocation();
	Rotation = GetViewRotation();
}

void ATeamAICharacter::GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const
{
	GetActorEyesViewPoint_Blueprint(Location, Rotation);
}

