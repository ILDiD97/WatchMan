// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrisonerCharacterController.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UENUM(BlueprintType)
enum class EActionPrisoner : uint8
{
	Use UMETA(DisplayName = "Use"),
	Give UMETA(DisplayName = "Give"),
	Fight UMETA(DisplayName = "Fight"),
};

UCLASS()
class WATCHMAN_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	UPROPERTY(VisibleAnywhere, Category = "Prisoner")
	APrisonerCharacterController* PrisonerOwner;

	UPROPERTY(VisibleAnywhere, Category = "Prisoner")
	APrisonerCharacterController* PrisonerReciever;

	UPROPERTY(VisibleAnywhere, Category = "ItemAction")
	EActionPrisoner Action;
	
	UPROPERTY(VisibleAnywhere, Category = "ItemAction")
	bool Use;

	UPROPERTY(VisibleAnywhere, Category = "ItemAction")
	bool Give;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ChooseAction(EActionPrisoner usage);
	
	virtual void UseItem();

    virtual void GiveItem();
};
