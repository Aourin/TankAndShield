// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;	
class UTurretBase;
class ATankProjectile;

UCLASS()
class TANKANDSHIELD_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	void MoveTowardLocation(FVector TargetLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretBaseReference(UTurretBase* TurretBase);

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void Move(float Throttle);

	UPROPERTY(EditAnywhere, Category = Firing)
    float FireSpeed = 90000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float BaseMovementSpeed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Firing)
	float BoostSpeed = 100.f;


	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float MaxMovementForce = 400000.f;

	float GetMaxTargettingDistance() const;

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditAnywhere, Category = Firing)
	float MaxTargettingDistance = 4000.f;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Firing")
	TSubclassOf<ATankProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = "Firing")
	TSubclassOf<UParticleEmitter> Explosion;

	
	UTankBarrel* Barrel = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.f;
	double LastFireTime = 0;
};
