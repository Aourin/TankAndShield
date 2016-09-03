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

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
}
