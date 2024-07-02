// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerCamera.h"
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

	UPROPERTY(EditAnywhere)
	APlayerCamera* Player;
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Context")
	class UInputMappingContext* InputContext;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Horizontal")
	UInputAction* MouseInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Vartical")
	UInputAction* VerticalInput;

	virtual void SetupInputComponent() override;

	void PlayerRotation(const FInputActionValue& Value);
};
