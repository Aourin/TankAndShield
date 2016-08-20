// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "TankController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BEGIN PLAY"));
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank Controlled"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank is %s"), *(ControlledTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

