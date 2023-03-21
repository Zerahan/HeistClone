// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/TeamPlayerController.h"

FGenericTeamId ATeamPlayerController::GetGenericTeamId() const
{
	return FGenericTeamId((uint8)TeamID);
}

ATeamPlayerController::ATeamPlayerController()
{
	TeamID = ETeamFaction::T_Thief;
}

ETeamFaction ATeamPlayerController::SetTeamID(ETeamFaction NewTeamID)
{
	TeamID = NewTeamID;
	SetGenericTeamId(FGenericTeamId((uint8)TeamID));
	return TeamID;
}
