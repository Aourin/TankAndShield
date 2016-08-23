// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "Public/TankProjectileMovement.h"
#include "TankProjectile.h"

// Sets default values
ATankProjectile::ATankProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankProjectileMovement = CreateDefaultSubobject<UTankProjectileMovement>(FName("Projectile Movement"));
	TankProjectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ATankProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called every frame
void ATankProjectile::LaunchProjectile(float Speed)
{
	auto Time = GetWorld()->GetTimeSeconds();
	TankProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	TankProjectileMovement->Activate();
}

