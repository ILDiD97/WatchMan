// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"


// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Arrow = CreateDefaultSubobject<UArrowComponent>("Pivot");
	RootComponent = Arrow;
	
	Monitor = CreateDefaultSubobject<UArrowComponent>("Monitor");
	Monitor->SetupAttachment(Arrow);
	
	CineCameraComponent = CreateDefaultSubobject<UCineCameraComponent>("CineCamera");
	CineCameraComponent->SetupAttachment(Arrow);
	CineCameraComponent->SetActive(true);

	RoomCineCameraComponent = CreateDefaultSubobject<UCineCameraComponent>("RommCamera");
	RoomCineCameraComponent->SetupAttachment(Arrow);
	RoomCineCameraComponent->SetActive(false);
}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();

	CineCameraComponent->SetWorldRotation(InitialRot);
}

// Called every frame
void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float relativeXRotation = CineCameraComponent->GetComponentRotation().Pitch;
	xRotAccel = FMath::Lerp(xRotAccel, MouseInput.Y * VerticalRotationSpeed,RotationHardness  * DeltaTime);
	const float XRotation = relativeXRotation + xRotAccel  * DeltaTime;
	const float clampedXRotation = FMath::Clamp(XRotation, -VerticalMaxLimit, VerticalMaxLimit);
	
	const float relativeYRotation = CineCameraComponent->GetComponentRotation().Yaw;
	yRotAccel = FMath::Lerp(yRotAccel, MouseInput.X * HorizontalRotationSpeed,RotationHardness * DeltaTime);
	const float YRotation = relativeYRotation + yRotAccel * DeltaTime;
	const float clampedYRotation = FMath::Clamp(YRotation, -HotizontalMaxLimit, HotizontalMaxLimit);


	const FRotator CameraHorizontalRotation = FRotator(clampedXRotation,
		clampedYRotation,
		0);
	CineCameraComponent->SetWorldRotation(CameraHorizontalRotation);
}

void APlayerCamera::CameraRotation(FVector2D rotationValue)
{
	MouseInput = rotationValue;
}

void APlayerCamera::ChangeCamera(bool change)
{
	CineCameraComponent->SetActive(!change);
	RoomCineCameraComponent->SetActive(change);
}

