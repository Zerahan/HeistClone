// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "HeistGameMode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class HEISTGAMECLONE_API AHeistGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay() override;
};
