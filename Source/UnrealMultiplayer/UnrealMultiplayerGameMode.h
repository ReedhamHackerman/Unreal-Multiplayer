// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealMultiplayerGameMode.generated.h"

UCLASS(minimalapi)
class AUnrealMultiplayerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealMultiplayerGameMode();

	void CompleteMission(APawn* instigatorPawn);

	UFUNCTION(BlueprintImplementableEvent,Category ="GameMode")
	void OnMissionComplete(APawn* instigatorpawn);
protected:
	UPROPERTY(EditDefaultsOnly,Category="Spectating")
	TSubclassOf<AActor> SpectatingViewPoint;
};



