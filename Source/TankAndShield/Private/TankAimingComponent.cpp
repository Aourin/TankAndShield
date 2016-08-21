// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Public/TankBarrel.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretBaseReference(UStaticMeshComponent* TurretBaseToSet)
{
	TurretBase = TurretBaseToSet;
}

//	Moves the barrel toward an aim Direction
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto TurretRotation = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	if (!TurretBase) { return; }
	auto DeltaRotator = AimRotator - TurretRotation;
	TurretBase->SetRelativeRotation(DeltaRotator);

	Barrel->Elevate(5);
}

void UTankAimingComponent::AimAt(FVector HitLocation, float FireSpeed)
{
	auto CurrentTankName = GetOwner()->GetName();
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	
	FVector StartLocation = Barrel->GetSocketLocation(FName("Turret_Out"));
	// UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from "), *CurrentTankName, *HitLocation.ToString());


	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		FireSpeed
	);

	if(bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		DrawDebugLine(GetWorld(), StartLocation, HitLocation, FColor::Red, false, -1.f, '\000', 10.f);
	}

}

