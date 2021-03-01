// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMultiplayerGameMode.h"
#include "UnrealMultiplayerHUD.h"
#include "UnrealMultiplayerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "kismet/GameplayStatics.h"
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
		
		if (SpectatingViewPoint)
		{
			TArray<AActor*> ReturnActors;

			UGameplayStatics::GetAllActorsOfClass(this, SpectatingViewPoint, ReturnActors);

			if (ReturnActors.Num() > 0)
			{
				AActor* NewActor = ReturnActors[0];
				APlayerController* pc = Cast<APlayerController>(instigatorPawn->GetController());
				if (pc)
				{
					pc->SetViewTargetWithBlend(NewActor, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
				}
			}

		}
		else
		{
			UE_LOG(LogTemp,Log,TEXT("Viewport Has not Been Setted to the base class Its null Pls Set the ViewPort"))
		}
		
		
	}
	
	OnMissionComplete(instigatorPawn);

	
}
