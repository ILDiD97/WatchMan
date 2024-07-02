// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	//RootComponent = SpringArm;
	
	//Arrow = CreateDefaultSubobject<UArrowComponent>("Pivot");
	//Arrow->SetupAttachment(RootComponent);

	//CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	//RootComponent = CameraComponent;
	
	CineCameraComponent = CreateDefaultSubobject<UCineCameraComponent>("CineCamera");
	RootComponent = CineCameraComponent;
}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCamera::CameraRotation(FVector2d rotationValue)
{
	const float relativeXRotation = GetActorRotation().Pitch;
	const float XRotation = relativeXRotation + rotationValue.Y * VerticalRotationSpeed * 0.1;
	const float clampedXRotation = FMath::Clamp(XRotation, -VerticalMaxLimit, VerticalMaxLimit);
	
	const float relativeYRotation = GetActorRotation().Yaw;
	const float YRotation = relativeYRotation + rotationValue.X * HorizontalRotationSpeed * 0.1f;
	const float clampedYRotation = FMath::Clamp(YRotation, -HotizontalMaxLimit, HotizontalMaxLimit);
	
	const FRotator CameraHorizontalRotation = FRotator(clampedXRotation,
		clampedYRotation,
		0);
	SetActorRotation(CameraHorizontalRotation);
}

