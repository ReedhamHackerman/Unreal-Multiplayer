// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAiCharacter.h"

// Sets default values
AFPSAiCharacter::AFPSAiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSAiCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSAiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSAiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

