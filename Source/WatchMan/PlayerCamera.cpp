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

// Called to bind functionality to input
void APlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCamera::HorizontalRotation(FVector2d rotationValue)
{
	const float relativeZRotation = CameraComponent->GetRelativeRotation().Roll;
	const FRotator CameraHorizontalRotation = FRotator(0,0,
		relativeZRotation + rotationValue.X * horizontalRotationSpeed * 0.1f);
	CameraComponent->AddRelativeRotation(CameraHorizontalRotation);
}

