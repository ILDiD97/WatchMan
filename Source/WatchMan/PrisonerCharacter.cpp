// Fill out your copyright notice in the Description page of Project Settings.


#include "PrisonerCharacter.h"
#include "PrisonerStatistics.h"


// Sets default values
APrisonerCharacter::APrisonerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Stats = CreateDefaultSubobject<UPrisonerStatistics>(TEXT("Stats"));

}

// Called when the game starts or when spawned
void APrisonerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrisonerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APrisonerCharacter::SetActionAnimation(EActionAnimation Action)
{
	ActionAnimation = Action;
}

void APrisonerCharacter::InitStats(FPrisonerStats Data)
{
	Stats->InitializeStats(Data);
}




