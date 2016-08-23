// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Public/TankBarrel.h"
#include "Public/TurretBase.h"
#include "Public/TankAimingComponent.h"
#include "Public/TankProjectile.h"
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
	Barrel = BarrelToSet;
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
void ATank::MoveTowardLocation(FVector TargetLocation)
{
	auto Time = GetWorld()->DeltaTimeSeconds;
	FVector Direction = (TargetLocation - GetActorLocation());
	SetActorRelativeLocation(GetActorLocation() + Direction.GetSafeNormal() * Time * BaseMovementSpeed);
}
void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded) {

		auto Time = GetWorld()->GetTimeSeconds();

		UE_LOG(LogTemp, Warning, TEXT("Firing!"));

		auto Projectile = GetWorld()->SpawnActor<ATankProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Turret_Out")),
			Barrel->GetSocketRotation(FName("Turret_Out"))
			);

		Projectile->LaunchProjectile(FireSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}
