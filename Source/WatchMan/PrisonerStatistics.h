// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrisonerCharacter.h"
#include "TimeManager.h"
#include "Components/ActorComponent.h"
#include "PrisonerStatistics.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WATCHMAN_API UPrisonerStatistics : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPrisonerStatistics();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D SanityLossRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D MoodLossRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseSanity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseMood;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SanityBreakPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoodBreakPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MoodPenaltyThisDay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float SanityPenaltyThisDay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ATimeManager* TimeManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APrisonerCharacter* OwnerCharacter;

	UFUNCTION()
	void OnDayEnd(int Days);
	
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsInsane;
	
	UFUNCTION(BlueprintCallable)
	void AddMoodPenalty(float Value);

	UFUNCTION(BlueprintCallable)
	void AddSanityPenalty(float Value);

	UFUNCTION(BlueprintCallable)
	void InitializeStats(FPrisonerStats Stats);
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
