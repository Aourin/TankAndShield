// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Booster.h"

void UBooster::SetThrottle(float Throttle)
{
	auto ForceApplied = BoostForce * Throttle * -GetForwardVector();
	auto ForceLocation = GetComponentLocation();
	auto RootTank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto Name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is moving with Force %s"), *Name, *ForceLocation.ToString());
	RootTank->AddForceAtLocation(ForceApplied, ForceLocation);
}


