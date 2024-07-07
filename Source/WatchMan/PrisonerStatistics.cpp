// Fill out your copyright notice in the Description page of Project Settings.


#include "PrisonerStatistics.h"
#include "Dice.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UPrisonerStatistics::UPrisonerStatistics()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UPrisonerStatistics::OnDayEnd(int Days)
{
	UE_LOG(LogTemp, Warning, TEXT("Day %d"), Days);

	const float SanityLoss = FMath::RandRange(SanityLossRange.X, SanityLossRange.Y);
	BaseSanity -= SanityLoss + SanityPenaltyThisDay;

	const float MoodLoss = FMath::RandRange(MoodLossRange.X, MoodLossRange.Y);
	BaseMood -= MoodLoss + MoodPenaltyThisDay;

	if(BaseMood < MoodBreakPoint && RollADice(12) > 7)
	{
		OwnerCharacter->SetActionAnimation(EActionAnimation::Sad);
	}

	IsInsane = BaseSanity < SanityBreakPoint && RollADice(12) > 7;
}

void UPrisonerStatistics::AddMoodPenalty(float Value)
{
	MoodPenaltyThisDay += Value;
}

void UPrisonerStatistics::AddSanityPenalty(float Value)
{
	SanityPenaltyThisDay += Value;
}

void UPrisonerStatistics::InitializeStats(FPrisonerStats Stats)
{
	Name = Stats.Name;
	SanityLossRange = Stats.SanityLossRange;
	MoodLossRange = Stats.MoodLossRange;
	BaseSanity = Stats.BaseSanity;
	BaseMood = Stats.BaseMood;
}

// Called when the game starts
void UPrisonerStatistics::BeginPlay()
{
	Super::BeginPlay();
	
	TimeManager = Cast<ATimeManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ATimeManager::StaticClass()));
	TimeManager->OnDayEnd.AddDynamic(this, &UPrisonerStatistics::OnDayEnd);

	OwnerCharacter = Cast<APrisonerCharacter>(GetOwner());
}


// Called every frame
void UPrisonerStatistics::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

