// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Booster.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UBooster* BoosterToSet)
{
	TargetBooster = BoosterToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throttle)
{
	if (!TargetBooster) { return; }

	TargetBooster->SetThrottle(Throttle);
}
