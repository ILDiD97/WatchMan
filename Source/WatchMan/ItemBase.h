// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrisonerCharacterController.h"
#include "QuestManager.h"
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

	UPROPERTY(EditAnywhere, Category = "Item")
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int PrisonerID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Prisoner")
	APrisonerCharacterController* CurrentOwner;

	UPROPERTY(EditAnywhere, Category = "ItemAction")
	EActionAnimation Action;

	UPROPERTY(VisibleAnywhere, Category = "ItemAction")
	EActionAnimation CurrentAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ItemAction")
	bool UseOnPrisoner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	AQuestManager* QuestManager;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual EActionAnimation ChooseAction(EActionPrisoner usage, APrisonerCharacterController* owner);
	
	virtual EActionAnimation UseItem();

    virtual EActionAnimation GiveItem();
};
