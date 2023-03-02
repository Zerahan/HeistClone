// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/TeamPawn.h"

// Sets default values
ATeamPawn::ATeamPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATeamPawn::GetActorEyesViewPoint_Blueprint_Implementation(FVector& Location, FRotator& Rotation) const
{
	Location = GetPawnViewLocation();
	Rotation = GetViewRotation();
}

void ATeamPawn::GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const
{
	GetActorEyesViewPoint_Blueprint(Location, Rotation);
}

