// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Booster.h"

void UBooster::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("Throttling %f"), Throttle);
	auto ForceApplied = BoostForce * Throttle * GetForwardVector();
	auto ForceLocation = GetComponentLocation();
	auto RootTank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	RootTank->AddForceAtLocation(ForceApplied, ForceLocation);
}


