// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

//	Holds Barrel Props and Elevates
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKANDSHIELD_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	//	Set Turret References
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretBaseReference(UStaticMeshComponent* TurretBaseToSet);

	void AimAt(FVector HitLocation, float FireSpeed);
private:
	UTankBarrel* Barrel = nullptr;
	UStaticMeshComponent* TurretBase = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

};
