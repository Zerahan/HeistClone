// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zone_Basic.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract)
class HEISTGAMECLONE_API AZone_Basic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZone_Basic();

	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//TSubclassOf<UShapeComponent> CollisionComponentClass;

	UPROPERTY(Instanced, EditDefaultsOnly)
	UShapeComponent* CollisionComponent;

//#ifdef WITH_EDITORONLY_DATA
public:
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, category = "Default")
	bool bBlockAll;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, category = "Default")
	bool bBlockVisibility;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, category = "Default")
	bool bBlockInteraction;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, category = "Default")
	bool bBlockPathing;
//#endif
#ifdef WITH_EDITOR
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	UShapeComponent* GetCollisionComponent() const;

};
