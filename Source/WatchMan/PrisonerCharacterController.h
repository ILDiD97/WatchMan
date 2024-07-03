// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PrisonerCharacter.h"
#include "PrisonerCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class WATCHMAN_API APrisonerCharacterController : public AAIController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	int ID;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APrisonerCharacter> PrisonerClass;

	UPROPERTY(EditAnywhere)
	APrisonerCharacter* Prisoner;

	UPROPERTY(EditAnywhere)
	FTransform SpawnTransform;

	UPROPERTY(EditAnywhere)
	FDataTableRowHandle PrisonerStats;
	
	UPROPERTY(EditAnywhere)
	FPrisonerStats Stats;

	UFUNCTION()
	void SpawnPrisoners(FTransform controllerTransform, int currentID);

	UFUNCTION(BlueprintCallable)
	void MoveToMousePoint(FVector loc);
};
