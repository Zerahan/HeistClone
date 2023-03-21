// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/HeistGameMode.h"
#include "Game/HeistGameSettings.h"

void AHeistGameMode::StartPlay()
{
	FGenericTeamId::SetAttitudeSolver(&UHeistGameSettings::GetAttitude);
	Super::StartPlay();
}
