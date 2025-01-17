// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TankProjectile.generated.h"

class UTankProjectileMovement;

UCLASS()
class TANKANDSHIELD_API ATankProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATankProjectile();
	void LaunchProjectile(float Speed);
protected:
	UTankProjectileMovement* TankProjectileMovement = nullptr;
private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

};
