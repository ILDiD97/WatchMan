// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardianPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void AGuardianPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCamera = Cast<APlayerCamera>(GetPawn());

	GuardianHUD = Cast<AGuardianHUD>(this->GetHUD());
	
	StartSpawnPrisoners();
}

void AGuardianPlayerController::StartSpawnPrisoners()
{
	UWorld* world = GetWorld();
	if(world)
	{
		FActorSpawnParameters SpawnParameters;
		for (int i = 0; i < 4; i++)
		{
			APrisonerCharacterController* controller =
				Cast<APrisonerCharacterController>(world->SpawnActor(
					PrisonerControllerClass, &SpawnTransforms[i],SpawnParameters));
			controller->ID = i;
			controller->SpawnPrisoners(SpawnTransforms[i], i);
			PrisonersController.Add(controller);
		}

		TimeManager = Cast<ATimeManager>(world->SpawnActor(
			TimeManagerClass, &PlayerCamera->GetTransform(),SpawnParameters));
	}
}

void AGuardianPlayerController::StartPrisonerSetup()
{
	StartPrisonerParameter();
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

	Input->BindAction(PrisonerSelectionInput,
		ETriggerEvent::Started, this, &AGuardianPlayerController::OnStartedInput);
	Input->BindAction(PrisonerSelectionInput,
		ETriggerEvent::Triggered, this, &AGuardianPlayerController::SelectPrisoner);
	Input->BindAction(PrisonerSelectionInput,
		ETriggerEvent::Triggered, this, &AGuardianPlayerController::SelectLocation);
	Input->BindAction(PrisonerSelectionInput,
		ETriggerEvent::Completed, this, &AGuardianPlayerController::GiveLocation);
	Input->BindAction(PrisonerSelectionInput,
		ETriggerEvent::Canceled, this, &AGuardianPlayerController::GiveLocation);
	
	Input->BindAction(PrisonerDeselectionInput,
		ETriggerEvent::Completed, this, &AGuardianPlayerController::DeselectPrisoner);

}

void AGuardianPlayerController::PlayerRotation(const FInputActionValue& Value)
{
	if(!CameraChange && !IsWidgetControlled)
	{
		FVector2d InputVector = Value.Get<FVector2D>();
		PlayerCamera->CameraRotation(InputVector);
	}
}

void AGuardianPlayerController::PlayerCameraChange(const FInputActionValue& Value)
{
	WaitToCameraRot = !WaitToCameraRot;
	if(!IsWidgetControlled)
	{
		CameraChange = !CameraChange;
		CameraChangeRotation();
	}
}

void AGuardianPlayerController::ChangeCamera()
{
	PlayerCamera->ChangeCamera(CameraChange);
	SetShowMouseCursor(CameraChange);
}

FRotator AGuardianPlayerController::CameraRot()
{
	FRotator rot = UKismetMathLibrary::FindLookAtRotation(
		PlayerCamera->CineCameraComponent->GetRelativeLocation(),
		PlayerCamera->Monitor->GetRelativeLocation());
	return rot;
}

APlayerCamera* AGuardianPlayerController::CameraCurrentRot()
{
	return PlayerCamera;
}

void AGuardianPlayerController::OnStartedInput(const FInputActionValue& Value)
{
	if(CurrentController && CameraChange && !IsWidgetControlled)
	{
		CurrentController->StopMovement();
	}
}

void AGuardianPlayerController::SelectPrisoner(const FInputActionValue& Value)
{
	if(CameraChange && !IsWidgetControlled)
	{
		FHitResult Hit;
		bool bHitSuccessful = false;
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Pawn, true, Hit);

		if (bHitSuccessful)
		{
			const APrisonerCharacter* charSelected = Cast<APrisonerCharacter>(Hit.GetActor());
			if(charSelected)
			{
				CurrentID = Cast<APrisonerCharacterController>(
					charSelected->GetController())->ID;
				CurrentController = PrisonersController[CurrentID];
			}
		}
	}
}

void AGuardianPlayerController::SelectLocation(const FInputActionValue& Value)
{
	if(CurrentController && CameraChange && !IsWidgetControlled)
	{
		// We look for the location in the world where the player has pressed the input
		FHitResult Hit;
		bool bHitSuccessful = false;

		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Camera, true, Hit);
		// If we hit a surface, cache the location
		if (bHitSuccessful)
		{
			CachedDestination = Hit.Location;
		}
		
	}
}

void AGuardianPlayerController::GiveLocation(const FInputActionValue& Value)
{
	if(CurrentController && CameraChange && !IsWidgetControlled)
	{
		CurrentController->MoveToMousePoint(CachedDestination);
	}
}

void AGuardianPlayerController::DeselectPrisoner(const FInputActionValue& Value)
{
	CurrentController = nullptr;
}

void AGuardianPlayerController::ItemAction(EActionPrisoner usage)
{
	Item->ChooseAction(usage);
}

void AGuardianPlayerController::EndDay()
{
	CurrentDay = TimeManager->NextDay();
}

void AGuardianPlayerController::ShowInputMessage(FString Message)
{
	GEngine->AddOnScreenDebugMessage(FMath::Rand(), 0.2f, FColor::Magenta, Message);
}

void AGuardianPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(Item)
	{
		Item->SetActorTransform(PrisonersController[ItemPrisoner]->Prisoner->GetTransform());
	}
}
