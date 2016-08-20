// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
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


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation)
{
	auto CurrentTankName = GetOwner()->GetName();

	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), HitLocation, FColor::Red, false, -1.f, '\000', 10.f);
	UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"), *CurrentTankName, *HitLocation.ToString());
}
