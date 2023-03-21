// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GenericTeamAgentInterface.h"
#include "TeamTypes.generated.h"

UENUM(BlueprintType)
enum class ETeamFaction : uint8
{
	T_Neutral	UMETA(DisplayName = "Neutral"),
	T_Guard		UMETA(DisplayName = "Guards"),
	T_Thief		UMETA(DisplayName = "Thieves"),
	//T_Neutral1	UMETA(DisplayName = "Neutral 1"),
	//T_Neutral2	UMETA(DisplayName = "Neutral 2"),
	//T_Neutral3	UMETA(DisplayName = "Neutral 3"),
	//T_Neutral4	UMETA(DisplayName = "Neutral 4"),
	//T_Guard1	UMETA(DisplayName = "Guards 1"),
	//T_Guard2	UMETA(DisplayName = "Guards 2"),
	//T_Guard3	UMETA(DisplayName = "Guards 3"),
	//T_Guard4	UMETA(DisplayName = "Guards 4"),
	//T_Thief1	UMETA(DisplayName = "Thieves 1"),
	//T_Thief2	UMETA(DisplayName = "Thieves 2"),
	//T_Thief3	UMETA(DisplayName = "Thieves 3"),
	//T_Thief4	UMETA(DisplayName = "Thieves 4"),
};

USTRUCT(BlueprintType)
struct HEISTGAMECLONE_API FTeamAttitude
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TEnumAsByte<ETeamAttitude::Type>> Attitude;
	
	FTeamAttitude(){};
	FTeamAttitude(TArray<TEnumAsByte<ETeamAttitude::Type>> List) { Attitude = List; };
};