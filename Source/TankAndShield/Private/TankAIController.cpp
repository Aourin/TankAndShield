// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Public/Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No AI Tank Controlled"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled AI Tank is %s"), *(ControlledTank->GetName()));
	}

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Cannot Find Player tank"));
	}
	else {
		TargetActor = PlayerTank;
		UE_LOG(LogTemp, Warning, TEXT("Set Target to %s"), *(TargetActor->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (ControlledTank && PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	}
}
bool ATankAIController::GetSightRayHitLocation(FVector & HitLocation) const
{
	return false;
}

/*
*	Gets the Tank Class of this Pawn
*/
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

/**
*	Gets the Player Tank in the world
*/
ATank* ATankAIController::GetPlayerTank() const
{		
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

