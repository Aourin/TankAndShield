// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No AI Tank Controlled"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled AI Tank is %s"), *(ControlledTank->GetName()));
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
