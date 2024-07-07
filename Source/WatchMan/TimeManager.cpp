// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ATimeManager::NextDay()
{
	if(Days <= 6)
	{
		Days++;
	
	}
	
	OnDayEnd.Broadcast(Days);
	
	return Days;
}

void ATimeManager::StartToZero()
{
	Days = 0;
}





