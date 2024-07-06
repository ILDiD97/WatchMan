// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/ArrowComponent.h"
#include "CinematicCamera/Public/CineCameraComponent.h"
#include "PlayerCamera.generated.h"


// Moved this here to make it easier to change
const float ROTATION_DELTA = 0.1f;

UCLASS()
class WATCHMAN_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

	UPROPERTY(EditAnywhere, Category = "Camera")
	UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UArrowComponent* Monitor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCineCameraComponent* CineCameraComponent;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCineCameraComponent* RoomCineCameraComponent;

	UPROPERTY(EditAnywhere, Category = "CameraStat")
	float HorizontalRotationSpeed;

	UPROPERTY(EditAnywhere, Category = "CameraStat")
	float HotizontalMaxLimit;

	UPROPERTY(EditAnywhere, Category = "CameraStat")
	float VerticalRotationSpeed;
	
	UPROPERTY(EditAnywhere, Category = "CameraStat")
	float VerticalMaxLimit;

	UPROPERTY(EditAnywhere, Category = "CameraStat")
	FRotator InitialRot;

	UPROPERTY(VisibleAnywhere, Category = "CameraStat")
	float xRotAccel = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "CameraStat")
	float yRotAccel = 0.0f;

	UPROPERTY(EditAnywhere, Category = "CameraStat")
	float RotationHardness = 6.0f;;

	UPROPERTY(VisibleAnywhere, Category = "CameraStat")
	FVector2D MouseInput;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void CameraRotation(FVector2D rotationValue);
	
	UFUNCTION(BlueprintImplementableEvent)
	void RotateCameraToMonitor(float alphaLerp);

	UFUNCTION()
	void ChangeCamera(bool change);
};
