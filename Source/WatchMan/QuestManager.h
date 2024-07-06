// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.generated.h"

USTRUCT(BlueprintType)
struct FQuestStruct
{
	GENERATED_BODY()

public :

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Quest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool QuestCompleted;
};

UCLASS()
class WATCHMAN_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestStruct> Quests;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
