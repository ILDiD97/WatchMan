// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerCamera.h"
#include "PrisonerCharacter.h"
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

	UPROPERTY(EditAnywhere)
	APlayerCamera* PlayerCamera;

	UPROPERTY(VisibleAnywhere)
	TArray<APrisonerCharacter*> Prisoners;

	UPROPERTY(VisibleAnywhere)
	bool CameraChange;

	virtual void SetupInputComponent() override;

	void PlayerRotation(const FInputActionValue& Value);

	void PlayerCameraChange(const FInputActionValue& Value);

	void ShowInputMessage(FString Message);
};
