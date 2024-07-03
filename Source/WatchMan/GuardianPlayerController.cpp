// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardianPlayerController.h"

#include "Kismet/GameplayStatics.h"

void AGuardianPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCamera = Cast<APlayerCamera>(GetPawn());

	UWorld* world = GetWorld();
	if(world)
	{
		for (int i = 0; i < 4; i++)
		{
		
		}
	}
}

void AGuardianPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputContext, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);

	Input->BindAction(RotateInput,
		ETriggerEvent::Triggered, this, &AGuardianPlayerController::PlayerRotation);
	Input->BindAction(RotateInput,
		ETriggerEvent::Completed, this, &AGuardianPlayerController::PlayerRotation);
	Input->BindAction(CameraSelectionInput,
		ETriggerEvent::Completed, this, &AGuardianPlayerController::PlayerCameraChange);
	
}

void AGuardianPlayerController::PlayerRotation(const FInputActionValue& Value)
{
	if(!CameraChange)
	{
		FVector2d InputVector = Value.Get<FVector2D>();
		//ShowInputMessage(InputVector.ToString());
		PlayerCamera->CameraRotation(InputVector);
	}
}

void AGuardianPlayerController::PlayerCameraChange(const FInputActionValue& Value)
{
	CameraChange = !CameraChange;
	PlayerCamera->ChangeCamera(CameraChange);
	SetShowMouseCursor(CameraChange);
}

void AGuardianPlayerController::ShowInputMessage(FString Message)
{
	GEngine->AddOnScreenDebugMessage(FMath::Rand(), 0.2f, FColor::Magenta, Message);
}
