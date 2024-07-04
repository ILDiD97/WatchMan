// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GuardianPlayerController.h"
#include "GuardianHUD.h"
#include "GameFramework/GameModeBase.h"
#include "WatchManGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class WATCHMAN_API AWatchManGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	AWatchManGameModeBase();

	
protected:
	
	virtual void BeginPlay() override;
};
