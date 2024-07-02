// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CinematicCamera/Public/CineCameraComponent.h"
#include "PlayerCamera.generated.h"

UCLASS()
class WATCHMAN_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

	//UPROPERTY(EditAnywhere)
	//USpringArmComponent* SpringArm;

	//UPROPERTY(EditAnywhere)
	//UArrowComponent* Arrow;

	//UPROPERTY(EditAnywhere)
	//UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere)
	UCineCameraComponent* CineCameraComponent;

	UPROPERTY(EditAnywhere)
	float HorizontalRotationSpeed;

	UPROPERTY(EditAnywhere)
	float HotizontalMaxLimit;

	UPROPERTY(EditAnywhere)
	float VerticalRotationSpeed;
	
	UPROPERTY(EditAnywhere)
	float VerticalMaxLimit;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void CameraRotation(FVector2d rotationValue);
};
