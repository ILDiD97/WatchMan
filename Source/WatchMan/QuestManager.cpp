// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuestManager::SetQuestBool(int idQuest, bool isCompleted)
{
	Quests[idQuest].QuestCompleted = isCompleted;
}

bool AQuestManager::EvaluateQuestsBool()
{
	for (FQuestStruct Element : Quests)
	{
		if(Element.QuestCompleted) Counter++;
	}

	if(Counter > 5) return true;
	else if (Counter == 0) return true;
	else return false;
}

