// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GenericTeamAgentInterface.h"
#include "Types/TeamTypes.h"
#include "HeistAIController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class HEISTGAMECLONE_API AHeistAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team", meta = (AllowPrivateAccess = "true"))
	ETeamFaction TeamID;
	
	UFUNCTION()
	FGenericTeamId GetGenericTeamId() const;
	
public:
	AHeistAIController();

	UFUNCTION(BlueprintCallable, Category = "Team")
	ETeamFaction SetTeamID(ETeamFaction NewTeamID);

	UFUNCTION(BlueprintCallable, Category = "Team")
	ETeamFaction GetTeamID() const;
};
