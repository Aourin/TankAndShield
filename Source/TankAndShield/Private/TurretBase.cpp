// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "TurretBase.h"

void UTurretBase::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond  * GetWorld()->DeltaTimeSeconds;
	auto DeltaRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, DeltaRotation, 0));
}


