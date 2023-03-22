// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HeistAITypes.generated.h"

UENUM(BlueprintType)
enum class EMood_AIState : uint8
{
	M_ASLEEP	UMETA(DisplayName = "Asleep"),
	M_IDLE		UMETA(DisplayName = "Idle"),
	M_CASUAL	UMETA(DisplayName = "Casual"),
	M_PARANOID	UMETA(DisplayName = "Paranoid"),
	M_ALERT		UMETA(DisplayName = "Alert"),
	M_PANIC		UMETA(DisplayName = "Panic"),
};

UENUM(BlueprintType)
enum class EWork_AIState : uint8
{
	W_NONCOMBAT		UMETA(DisplayName = "Civilian"),
	W_GUARD_OFFDUTY	UMETA(DisplayName = "Offduty Guard"),
	W_GUARD_ONDUTY	UMETA(DisplayName = "Onduty Guard"),
	W_PRO_OFFDUTY	UMETA(DisplayName = "Offduty Professional"),
	W_PRO_ONDUTY	UMETA(DisplayName = "Onduty Professional"),
};
