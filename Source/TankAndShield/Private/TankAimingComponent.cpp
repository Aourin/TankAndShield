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

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
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


void UTankAimingComponent::AimAt(FVector HitLocation, float FireSpeed)
{
	auto CurrentTankName = GetOwner()->GetName();
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	
	FVector StartLocation = Barrel->GetSocketLocation(FName("Turret_Out"));
	// UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from "), *CurrentTankName, *HitLocation.ToString());


	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		FireSpeed,
		false,
		0,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor*>(), true)
		) {

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		Barrel->SetRelativeRotation(AimDirection.ToOrientationRotator());
		DrawDebugLine(GetWorld(), StartLocation, HitLocation, FColor::Red, false, -1.f, '\000', 10.f);
	}

}

