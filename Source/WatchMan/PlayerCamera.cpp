// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	RootComponent = SpringArm;
	
	Arrow = CreateDefaultSubobject<UArrowComponent>("Pivot");
	Arrow->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(Arrow);
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
	const float relativeYRotation = CameraComponent->GetRelativeRotation().Yaw;
	const float yRotation = relativeYRotation + rotationValue.Y * VerticalRotationSpeed * 0.1;
	const float clampedYRotation = FMath::Clamp(yRotation, 0, VerticalMaxLimit);
	
	const float relativeZRotation = CameraComponent->GetRelativeRotation().Roll;
	const float zRotation = relativeZRotation + rotationValue.X * HorizontalRotationSpeed * 0.1f;
	const float clampedZRotation = FMath::Clamp(zRotation, 0, HotizontalMaxLimit);
	
	const FRotator CameraHorizontalRotation = FRotator(0,clampedYRotation,
		clampedZRotation);
	CameraComponent->AddRelativeRotation(CameraHorizontalRotation);
}

