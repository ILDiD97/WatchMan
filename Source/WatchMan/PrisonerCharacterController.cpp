// Fill out your copyright notice in the Description page of Project Settings.


#include "PrisonerCharacterController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

void APrisonerCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

void APrisonerCharacterController::SpawnPrisoners(FTransform controllerTransform,
	int currentID, USkeletalMesh* MeshComponent)
{
	UWorld* world = GetWorld();
	
	if (world)
	{
		const FActorSpawnParameters SpawnParameters;
		Prisoner = Cast<APrisonerCharacter>(world->SpawnActor(
			PrisonerClass, &controllerTransform, SpawnParameters));
		Possess(Prisoner);
		Prisoner->SetSkeletalCharachter(MeshComponent);
		BedLocation = controllerTransform.GetLocation();
	}
}

void APrisonerCharacterController::MoveToMousePoint(FVector loc)
{
	CurrentMouseLocation = loc;
}




