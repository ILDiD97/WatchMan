// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"


// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	//RootComponent = SpringArm;
	
	Arrow = CreateDefaultSubobject<UArrowComponent>("Pivot");
	RootComponent = Arrow;

	//CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	//RootComponent = CameraComponent;
	
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

}

void APlayerCamera::CameraRotation(FVector2d rotationValue)
{
	const float relativeXRotation = CineCameraComponent->GetComponentRotation().Pitch;
	const float XRotation = relativeXRotation + rotationValue.Y * VerticalRotationSpeed * 0.1;
	const float clampedXRotation = FMath::Clamp(XRotation, -VerticalMaxLimit, VerticalMaxLimit);
	
	const float relativeYRotation = CineCameraComponent->GetComponentRotation().Yaw;
	const float YRotation = relativeYRotation + rotationValue.X * HorizontalRotationSpeed * 0.1f;
	const float clampedYRotation = FMath::Clamp(YRotation, -HotizontalMaxLimit, HotizontalMaxLimit);
	
	const FRotator CameraHorizontalRotation = FRotator(clampedXRotation,
		clampedYRotation,
		0);
	CineCameraComponent->SetWorldRotation(CameraHorizontalRotation);
}

void APlayerCamera::ChangeCamera(bool change)
{
	CineCameraComponent->SetActive(!change);
	RoomCineCameraComponent->SetActive(change);
}

