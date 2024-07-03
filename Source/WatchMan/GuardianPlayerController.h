// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerCamera.h"
#include "PrisonerCharacterController.h"
#include "GuardianPlayerController.generated.h"

/**
 * 
 */

UCLASS()
class WATCHMAN_API AGuardianPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Context")
	class UInputMappingContext* InputContext;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Rotation")
	UInputAction* RotateInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Camera Selection")
	UInputAction*  CameraSelectionInput;
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Prisoner Selection")
	UInputAction*  PrisonerSelectionInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Prisoner Deselection")
	UInputAction*  PrisonerDeselectionInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Location Selection")
	UInputAction*  LocationSelectionInput;
	
	UPROPERTY(EditAnywhere)
	APlayerCamera* PlayerCamera;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APrisonerCharacterController>  PrisonerControllerClass;
	
	UPROPERTY(VisibleAnywhere)
	TArray<APrisonerCharacterController*> PrisonersController;
	
	UPROPERTY(EditAnywhere)
	TArray<FTransform> SpawnTransforms;

	UPROPERTY(VisibleAnywhere)
	APrisonerCharacterController* CurrentController;

	UPROPERTY(VisibleAnywhere)
	int CurrentID;
	
	UPROPERTY(EditAnywhere)
	FVector CachedDestination;
	
	UPROPERTY(VisibleAnywhere)
	bool CameraChange;

	UFUNCTION()
	void StartSpawnPrisoners();
	
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void PlayerRotation(const FInputActionValue& Value);

	UFUNCTION()
	void PlayerCameraChange(const FInputActionValue& Value);

	UFUNCTION()
	void OnStartedInput(const FInputActionValue& Value);
	
	UFUNCTION()
	void SelectPrisoner(const FInputActionValue& Value);

	UFUNCTION()
	void SelectLocation(const FInputActionValue& Value);
	
	UFUNCTION()
	void GiveLocation(const FInputActionValue& Value);
	
	UFUNCTION()
	void DeselectPrisoner(const FInputActionValue& Value);

	void ShowInputMessage(FString Message);
};
