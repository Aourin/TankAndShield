// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TANKANDSHIELD_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	AActor* TargetActor;
	
private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	bool GetSightRayHitLocation(FVector &HitLocation) const;
};
