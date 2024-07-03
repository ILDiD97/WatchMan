// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "PrisonerCharacter.generated.h"

USTRUCT(BlueprintType)
struct FPrisonerStats
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	int Health;

	UPROPERTY(EditAnywhere)
	float Madness;
	
};

USTRUCT(BlueprintType)
struct WATCHMAN_API FDataPrisoner : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FPrisonerStats stat;
	
};

UCLASS()
class WATCHMAN_API APrisonerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APrisonerCharacter();

	UPROPERTY(EditAnywhere, Category = "PrisonerStats")
	FPrisonerStats Stats;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
