// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardianPlayerController.h"

#include "Kismet/GameplayStatics.h"

void AGuardianPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCamera = Cast<APlayerCamera>(GetPawn());
}

void AGuardianPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputContext, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);

	Input->BindAction(MouseInput,
		ETriggerEvent::Triggered, this, &AGuardianPlayerController::PlayerRotation);
	Input->BindAction(MouseInput,
		ETriggerEvent::Completed, this, &AGuardianPlayerController::PlayerRotation);
	
}

void AGuardianPlayerController::PlayerRotation(const FInputActionValue& Value)
{
	FVector2d InputVector = Value.Get<FVector2D>();
	//ShowInputMessage(InputVector.ToString());
	PlayerCamera->CameraRotation(InputVector);
}

void AGuardianPlayerController::ShowInputMessage(FString Message)
{
	GEngine->AddOnScreenDebugMessage(FMath::Rand(), 0.2f, FColor::Magenta, Message);
}
