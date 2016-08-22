// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Public/TankBarrel.h"
#include "Public/TurretBase.h"
#include "Public/TankAimingComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}
void ATank::SetTurretBaseReference(UTurretBase* TurretBaseToSet)
{
	TankAimingComponent->SetTurretBaseReference(TurretBaseToSet);
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, FireSpeed);
}

float ATank::GetMaxTargettingDistance() const
{
	return MaxTargettingDistance;
}

