// Fill out your copyright notice in the Description page of Project Settings.


#include "PrisonerCharacterController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

void APrisonerCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

void APrisonerCharacterController::SpawnPrisoners(FTransform controllerTransform, int currentID)
{
	UWorld* world = GetWorld();
	
	if (world)
	{
		const FActorSpawnParameters SpawnParameters;
		Prisoner = Cast<APrisonerCharacter>(world->SpawnActor(
			PrisonerClass, &controllerTransform, SpawnParameters));
		//Prisoner->ControllerID = currentID;
		Possess(Prisoner);
	}
}

void APrisonerCharacterController::MoveToMousePoint(FVector loc)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, loc);
	//MoveToLocation(loc);
}


