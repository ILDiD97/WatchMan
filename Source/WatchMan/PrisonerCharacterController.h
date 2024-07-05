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

	UPROPERTY(EditAnywhere, Category = "Controller")
	int ID;

	UPROPERTY(EditAnywhere, Category = "Controller")
	TSubclassOf<APrisonerCharacter> PrisonerClass;

	UPROPERTY(EditAnywhere, Category = "Controller")
	APrisonerCharacter* Prisoner;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrisonerStat")
	FPrisonerStats Stats;
	

	UFUNCTION()
	void SpawnPrisoners(FTransform controllerTransform, int currentID);

	UFUNCTION(BlueprintCallable)
	void MoveToMousePoint(FVector loc);
};
