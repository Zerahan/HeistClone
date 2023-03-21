// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/HeistGameSettings.h"

/**
 *
	T_Neutral	UMETA(DisplayName = "Neutral"),
	T_Guard		UMETA(DisplayName = "Guards"),
	T_Thief		UMETA(DisplayName = "Thieves"),
 */
UHeistGameSettings::UHeistGameSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// {T_Neutral, T_Guard, T_Theif}

	//Neutral
	TeamAttitudes.Add(FTeamAttitude({ ETeamAttitude::Friendly, ETeamAttitude::Neutral, ETeamAttitude::Neutral }));

	//Guards
	TeamAttitudes.Add(FTeamAttitude({ ETeamAttitude::Neutral, ETeamAttitude::Friendly, ETeamAttitude::Hostile }));

	//Thieves
	TeamAttitudes.Add(FTeamAttitude({ ETeamAttitude::Neutral, ETeamAttitude::Hostile, ETeamAttitude::Friendly }));
}

const UHeistGameSettings* UHeistGameSettings::Get()
{
	return GetDefault<UHeistGameSettings>();
}

ETeamAttitude::Type UHeistGameSettings::GetAttitude(FGenericTeamId FromTeam, FGenericTeamId ToTeam)
{
	auto & TeamAttitudes = UHeistGameSettings::Get()->TeamAttitudes;
	if (!TeamAttitudes.IsValidIndex(FromTeam.GetId())) return ETeamAttitude::Hostile;
	if (!TeamAttitudes.IsValidIndex(ToTeam.GetId())) return ETeamAttitude::Hostile;

	auto & Attitudes = TeamAttitudes[FromTeam.GetId()].Attitude;

	if (!Attitudes.IsValidIndex(ToTeam.GetId())) return ETeamAttitude::Hostile;

	return Attitudes[ToTeam.GetId()];
}
