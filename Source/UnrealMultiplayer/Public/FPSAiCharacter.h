// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAiCharacter.generated.h"
class UPawnSensingComponent;
UCLASS()
class UNREALMULTIPLAYER_API AFPSAiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSAiCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,Category="Component")
	UPawnSensingComponent* PawnSensingComp;

	UFUNCTION()
	void OnPawnSeen(APawn* Pawn);

	UFUNCTION()
	void OnHearSound(APawn* NoiseInstigator, const FVector& Location, float Volume);

	UPROPERTY(EditInstanceOnly, Category = "Rotation")
	float rotationSpeed;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
