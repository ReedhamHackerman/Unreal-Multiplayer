// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAiCharacter.h"
#include "perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
// Sets default values
AFPSAiCharacter::AFPSAiCharacter()
{
	
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
	
	
}

// Called when the game starts or when spawned
void AFPSAiCharacter::BeginPlay()
{
	
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AFPSAiCharacter::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AFPSAiCharacter::OnHearSound);
	Super::BeginPlay();
	
}

void AFPSAiCharacter::OnPawnSeen(APawn* Pawn)
{
	if (Pawn==nullptr)
	{
		return;
	}
	DrawDebugSphere(GetWorld(), Pawn->GetActorLocation(), 32.0f, 12, FColor::Yellow, false, 10.0f);
}

void AFPSAiCharacter::OnHearSound(APawn * NoiseInstigator, const FVector & Location, float Volume)
{
	DrawDebugSphere(GetWorld(), NoiseInstigator->GetActorLocation(), 32.0f, 12, FColor::Red, false, 10.0f);
	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();
	FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
	NewLookAt.Pitch = 0.0f;
	NewLookAt.Roll = 0.0f;
	SetActorRotation(NewLookAt*rotationSpeed);
}

// Called every frame
void AFPSAiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


