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
	
};

USTRUCT(BlueprintType)
struct WATCHMAN_API FDataPrisoner : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPrisonerStats stat;
	
};

UENUM(BlueprintType)
enum class EActionAnimation : uint8
{
	BaseLocomotion UMETA(DisplayName = "BaseLocomotion"),
	Sad UMETA(DisplayName = "Sad"),
	Crying UMETA(DisplayName = "Crying"),
	Sleeping UMETA(DisplayName = "Sleeping"),
	Laughing UMETA(DisplayName = "Laughing"),
	Fight UMETA(DisplayName = "Fight"),
	Mirroring UMETA(DisplayName = "Mirroring"),
	Give UMETA(DisplayName = "Give"),
	Eat UMETA(DisplayName = "Eat"),
	Read UMETA(DisplayName = "Read"),
	LazeAround UMETA(DisplayName = "LazeAround"),
	ThrowCoin UMETA(DisplayName = "ThrowCoin"),
	Win UMETA(DisplayName = "Win"),
	Damaged UMETA(DisplayName = "Damaged"),
	Dead UMETA(DisplayName = "Dead"),
};

UCLASS()
class WATCHMAN_API APrisonerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APrisonerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prisoner Stats")
	class UPrisonerStatistics* Stats;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Prisoner Animation")
	EActionAnimation ActionAnimation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Prisoner Animation")
	bool IsInAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetSkeletalCharachter(USkeletalMesh* SkeletalMeshComponent);

	UFUNCTION(BlueprintCallable)
	void SetActionAnimation(EActionAnimation Action);

	UFUNCTION(BlueprintCallable)
	void InitStats(FPrisonerStats Data);
};
