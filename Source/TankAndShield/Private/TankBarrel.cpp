// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto Time = GetWorld()->GetTimeSeconds();
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

void UTankBarrel::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire in Barrel"));
}