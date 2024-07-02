// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardianPlayerController.h"

void AGuardianPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AGuardianPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UWorld* world = GetWorld();
	if(world)
	{
		FActorSpawnParameters SpawnParameters;
		Player = Cast<APlayerCamera>(GetLocalPlayer());
		//Player->PossessedBy(this);
	}
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputContext, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);

	Input->BindAction(MouseInput,
		ETriggerEvent::Triggered, this, &AGuardianPlayerController::PlayerRotation);
	Input->BindAction(MouseInput, ETriggerEvent::Completed, this, &AGuardianPlayerController::PlayerRotation);
}

void AGuardianPlayerController::PlayerRotation(const FInputActionValue& Value)
{
}
