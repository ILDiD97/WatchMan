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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controller")
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controller")
	bool IsPlayerControlled;

	UPROPERTY(EditAnywhere, Category = "Controller")
	TSubclassOf<APrisonerCharacter> PrisonerClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controller")
	APrisonerCharacter* Prisoner;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrisonerStat")
	FPrisonerStats Stats;

	UPROPERTY(EditAnywhere, Category = "Tree")
	UBehaviorTree* AITree;

	UPROPERTY(EditAnywhere, Category = "Tree")
	UBlackboardComponent* BBTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	FVector CurrentMouseLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	FVector BedLocation;

	UFUNCTION()
	void SpawnPrisoners(FTransform controllerTransform, int currentID, USkeletalMesh* MeshComponent);

	UFUNCTION(BlueprintCallable)
	void MoveToMousePoint(FVector loc);

};
