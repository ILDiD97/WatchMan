// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/ArrowComponent.h"
#include "CinematicCamera/Public/CineCameraComponent.h"
#include "PlayerCamera.generated.h"

UCLASS()
class WATCHMAN_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

	UPROPERTY(EditAnywhere, Category = "Camera")
	UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere, Category = "Camera")
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
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void CameraRotation(FVector2d rotationValue);

	void ChangeCamera(bool change);
};
