// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "Types/TeamTypes.h"
#include "TeamPlayerController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class HEISTGAMECLONE_API ATeamPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team", meta = (AllowPrivateAccess = "true"))
	ETeamFaction TeamID;

	UFUNCTION()
	virtual FGenericTeamId GetGenericTeamId() const override;

public:
	ATeamPlayerController();

	UFUNCTION(BlueprintCallable, Category = "Team")
	ETeamFaction SetTeamID(ETeamFaction NewTeamID);
	
};
