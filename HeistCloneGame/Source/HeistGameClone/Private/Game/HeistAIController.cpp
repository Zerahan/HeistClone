// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/HeistAIController.h"

FGenericTeamId AHeistAIController::GetGenericTeamId() const
{
	return FGenericTeamId((uint8)TeamID);
}

AHeistAIController::AHeistAIController()
{
	TeamID = ETeamFaction::T_Guard;
}

ETeamFaction AHeistAIController::SetTeamID(ETeamFaction NewTeamID)
{
	TeamID = NewTeamID;
	SetGenericTeamId(GetGenericTeamId());
	return TeamID;
}

ETeamFaction AHeistAIController::GetTeamID() const { return TeamID; }
