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
	}
	
}


void ATankAIController::AimAtLocation(ATank* ControlledTank, FVector TargetLocation) const
{

	if (ControlledTank)
	{
		FVector Distance = (TargetLocation - ControlledTank->GetActorLocation());
		UE_LOG(LogTemp, Warning, TEXT("Range to Player %f"), Distance.Size());
		//	Check the size and aim if with range
		if (Distance.Size() < ControlledTank->GetMaxTargettingDistance())
		{
			UE_LOG(LogTemp, Warning, TEXT("Enemy Has Site on Player %f"), Distance.Size());
			ControlledTank->AimAt(TargetLocation);
			ControlledTank->Fire();
		}
		else {
			ControlledTank->MoveTowardLocation(TargetLocation);
		}
		
	}

}
bool ATankAIController::GetSightRayHitLocation(FVector & HitLocation) const
{
	return false;
}