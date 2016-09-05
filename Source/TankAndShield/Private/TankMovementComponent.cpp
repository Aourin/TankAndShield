// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Booster.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UBooster* MainToSet, UBooster* LeftToSet, UBooster* RightToSet)
{
	MainBooster = MainToSet;
	LeftBooster = LeftToSet;;
	RightBooster = RightToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throttle)
{
	if (!MainBooster) { 
		UE_LOG(LogTemp, Warning, TEXT("NO Target Booster on %s"), *GetOwner()->GetName());
		return;
	}
	auto ForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	MainBooster->SetThrottle(-Throttle);
}

void UTankMovementComponent::IntendTurnRight(float Throttle)
{
	if (!MainBooster) {
		UE_LOG(LogTemp, Warning, TEXT("Missing Booster MAIN - %s"), *GetOwner()->GetName());
		return;

	}
	if (!LeftBooster) {
		UE_LOG(LogTemp, Warning, TEXT("Missing Booster LEFT - %s"), *GetOwner()->GetName());
		return;
	}
	if (!RightBooster) {
		UE_LOG(LogTemp, Warning, TEXT("Missing Booster RIGHT - %s"), *GetOwner()->GetName());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("%s Turn Right Result %f"), *GetOwner()->GetName(), Throttle);
	if (Throttle > 0) {
		LeftBooster->SetThrottle(-Throttle);
		RightBooster->SetThrottle(Throttle);
	}
	else if (Throttle < 0) {
		LeftBooster->SetThrottle(-Throttle);
		RightBooster->SetThrottle(Throttle);
	}
	
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	
	UE_LOG(LogTemp, Warning, TEXT("%s MOVE TO PLAYER %s"), *GetOwner()->GetName(),*MoveVelocity.ToString());
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	auto TurnThrow = FVector::CrossProduct(AIForwardIntention, TankForward);

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(TurnThrow.Z);
}
