// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTurretBase;
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
	void SetTurretBaseReference(UTurretBase* TurretBaseToSet);

	void AimAt(FVector HitLocation, float FireSpeed);
	void Fire();
private:
	UTankBarrel* Barrel = nullptr;
	UTurretBase* TurretBase = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

};
