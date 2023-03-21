// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Types/TeamTypes.h"
#include "GenericTeamAgentInterface.h"
#include "HeistGameSettings.generated.h"

/**
 * 
 */
UCLASS(DefaultConfig, Config = Game)
class HEISTGAMECLONE_API UHeistGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Config, Category = "Heist|AI")
	TArray<FTeamAttitude> TeamAttitudes;

	UHeistGameSettings(const FObjectInitializer& ObjectInitializer);

	static const UHeistGameSettings* Get();

	UFUNCTION(BlueprintPure, Category = "Heist|AI")
	static ETeamAttitude::Type GetAttitude(FGenericTeamId FromTeam, FGenericTeamId ToTeam);
};
