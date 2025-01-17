// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Public/Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ControlledTank && PlayerTank)
	{
		
		AimAtLocation(ControlledTank, PlayerTank->GetActorLocation()); 
	
		FVector Distance = (PlayerTank->GetActorLocation() - ControlledTank->GetActorLocation());
		//	Check the size and aim if with range
		if (Distance.Size() > ControlledTank->GetMaxTargettingDistance())
		{
			MoveToActor(PlayerTank, ControlledTank->GetMaxTargettingDistance() * 0.7f, true, true, false);
		}
	}
	
}

void ATankAIController::AimAtLocation(ATank* ControlledTank, FVector TargetLocation) const
{

	if (ControlledTank)
	{
		FVector Distance = (TargetLocation - ControlledTank->GetActorLocation());
		//	Check the size and aim if with range
		if (Distance.Size() < ControlledTank->GetMaxTargettingDistance())
		{
			ControlledTank->AimAt(TargetLocation);
			ControlledTank->Fire();
		}		
	}

}
bool ATankAIController::GetSightRayHitLocation(FVector & HitLocation) const
{
	return false;
}