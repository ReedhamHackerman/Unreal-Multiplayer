// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMultiplayerGameMode.h"
#include "UnrealMultiplayerHUD.h"
#include "UnrealMultiplayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealMultiplayerGameMode::AUnrealMultiplayerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealMultiplayerHUD::StaticClass();
}

void AUnrealMultiplayerGameMode::CompleteMission(APawn* instigatorPawn)
{
	if (instigatorPawn)
	{
		instigatorPawn->DisableInput(nullptr);
	}
	
	OnMissionComplete(instigatorPawn);
}
