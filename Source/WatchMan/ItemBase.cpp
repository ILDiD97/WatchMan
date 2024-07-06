// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>("Item");
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

EActionAnimation AItemBase::ChooseAction(EActionPrisoner usage, APrisonerCharacterController* owner)
{
	CurrentOwner = owner;
	switch (usage)
	{
		case EActionPrisoner::Use:
			return UseItem();
		case EActionPrisoner::Give:
			return GiveItem();
		default:
			return EActionAnimation::Laughing;
	}
}

EActionAnimation AItemBase::UseItem()
{
	CurrentAction = Action;
	return Action;
}

EActionAnimation AItemBase::GiveItem()
{
	CurrentAction = EActionAnimation::Give;
	return EActionAnimation::Give;
}

