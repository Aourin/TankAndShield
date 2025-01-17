// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Public/TankBarrel.h"
#include "Public/TurretBase.h"
#include "Public/TankProjectile.h"
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

void UTankAimingComponent::SetTurretBaseReference(UTurretBase* TurretBaseToSet)
{
	TurretBase = TurretBaseToSet;
}

//	Moves the barrel toward an aim Direction
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto TurretRotation = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	if (!TurretBase || !Barrel) { return; }

	//UE_LOG(LogTemp, Warning, TEXT("Move Barrel Towards"));
	auto DeltaRotator = AimRotator - TurretRotation;

	//Rotate and elevate Barrel and Base
	Barrel->Elevate(DeltaRotator.Pitch);
	TurretBase->Rotate(DeltaRotator.Yaw);
}

void UTankAimingComponent::AimAt(FVector HitLocation, float FireSpeed)
{
	auto CurrentTankName = GetOwner()->GetName();
	if (!Barrel) {
		UE_LOG(LogTemp, Warning, TEXT("Tank %s Has No Barrel"), *CurrentTankName); 
		return;
	}
	FVector OutLaunchVelocity;
	
	FVector StartLocation = Barrel->GetSocketLocation(FName("Turret_Out"));
	// UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from "), *CurrentTankName, *HitLocation.ToString());


	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		FireSpeed,
		false,
		1.f,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor*>(), false
	);

	if(bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//auto AimDirection = (HitLocation - StartLocation).GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		DrawDebugLine(GetWorld(), StartLocation, HitLocation, FColor::Red, false, -1.f, '\000', 10.f);
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("NO Aim Solution %f"), GetWorld()->GetTimeSeconds());
	}

}

void UTankAimingComponent::Fire()
{
	if (!Barrel) { return; }
	
	Barrel->Fire();
}

