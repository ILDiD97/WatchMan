// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS()
class WATCHMAN_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeManager();

	UPROPERTY(VisibleAnywhere)
	int Days;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsWin;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	int NextDay();

	UFUNCTION(BlueprintCallable)
	void StartToZero();
};
