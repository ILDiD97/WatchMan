// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GuardianHUD.h"
#include "ItemBase.h"
#include "PlayerCamera.h"
#include "PrisonerCharacterController.h"
#include "QuestManager.h"
#include "TimeManager.h"
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
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Context")
	class UInputMappingContext* InputContext;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Rotation")
	UInputAction* RotateInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Camera Selection")
	UInputAction*  CameraSelectionInput;
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Prisoner Selection")
	UInputAction*  PrisonerSelectionInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Prisoner Deselection")
	UInputAction*  PrisonerDeselectionInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Location Selection")
	UInputAction*  LocationSelectionInput;

	UPROPERTY(EditAnywhere, Category = "Prisoners")
	TSubclassOf<APrisonerCharacterController>  PrisonerControllerClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Prisoners")
	TArray<APrisonerCharacterController*> PrisonersController;

	UPROPERTY(EditAnywhere, Category = "Prisoner")
	TArray<USkeletalMesh*> SkeletalMeshes;
	
	UPROPERTY(EditAnywhere, Category = "Prisoners")
	TArray<FTransform> SpawnTransforms;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Prisoners")
	APrisonerCharacterController* CurrentController;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Prisoners")
	int CurrentID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prisoners")
	FVector CachedDestination;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Prisoners")
	FDataTableRowHandle PrisonerStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	APlayerCamera* PlayerCamera;
	
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	bool CameraChange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	bool WaitToCameraRot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interface")
	AGuardianHUD* GuardianHUD;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interface")
	bool IsWidgetControlled;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time")
	ATimeManager* TimeManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time")
	int CurrentDay;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
	AItemBase* Item;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
	int ItemPrisoner;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
	int PrisonerSub;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	TSubclassOf<AQuestManager> QuestManagerClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Quest")
	AQuestManager* QuestManager;
	
	UFUNCTION()
	void StartSpawnPrisoners();

	UFUNCTION(BlueprintCallable)
	void StartPrisonerSetup();
	
	UFUNCTION(BlueprintImplementableEvent)
	void StartPrisonerParameter();
	
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void PlayerRotation(const FInputActionValue& Value);

	UFUNCTION()
	void PlayerCameraChange(const FInputActionValue& Value);

	UFUNCTION(BlueprintImplementableEvent)
	void CameraChangeRotation();

	UFUNCTION(BlueprintCallable)
	void ResetCameraToStart();
	
	UFUNCTION(BlueprintCallable)
	void ChangeCamera();

	UFUNCTION(BlueprintImplementableEvent)
	void DeselectPrisonerVisibility();

	UFUNCTION(BlueprintPure)
	FRotator CameraRot();

	UFUNCTION(BlueprintPure)
	APlayerCamera* CameraCurrentRot();

	UFUNCTION()
	void OnStartedInput(const FInputActionValue& Value);
	
	UFUNCTION()
	void SelectPrisoner(const FInputActionValue& Value);

	UFUNCTION(BlueprintImplementableEvent)
	void SelectedPrisonerVisibility();

	UFUNCTION()
	void SelectLocation(const FInputActionValue& Value);
	
	UFUNCTION()
	void GiveLocation(const FInputActionValue& Value);
	
	UFUNCTION()
	void DeselectPrisoner(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void ItemAction(EActionPrisoner usage);

	UFUNCTION(BlueprintImplementableEvent)
	void AttachItemToSocket();

	UFUNCTION(BlueprintCallable)
	void EndDay();

	void ShowInputMessage(FString Message);
	
	virtual void Tick(float DeltaSeconds) override;
};
