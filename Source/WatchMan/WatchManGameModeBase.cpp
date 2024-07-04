// Copyright Epic Games, Inc. All Rights Reserved.


#include "WatchManGameModeBase.h"





AWatchManGameModeBase::AWatchManGameModeBase()
{
	const ConstructorHelpers::FClassFinder<APlayerController>
		PlayerControllerFinder(
			TEXT("/Game/Player/Input/BP_GuardianPlayer"));

	PlayerControllerClass = PlayerControllerFinder.Class;
	
	const ConstructorHelpers::FClassFinder<APawn>
		PlayerPawnFinder(TEXT("/Game/Player/BP_PlayerCamera"));

	DefaultPawnClass = PlayerPawnFinder.Class;

	const ConstructorHelpers::FClassFinder<AGuardianHUD>
		HUDFinder(
			TEXT("/Game/UserInterface/BP_GuardianHUD"));

	HUDClass = HUDFinder.Class;
	
}

void AWatchManGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	
}


