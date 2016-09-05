// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UBooster;
/**
 * 
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Lighting"))
class TANKANDSHIELD_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UBooster* MainToSet, UBooster* LeftToSet, UBooster* RightToSet);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveForward(float Throttle);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendTurnRight(float Throttle);

	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
	UBooster* MainBooster = nullptr;
	UBooster* LeftBooster = nullptr;
	UBooster* RightBooster = nullptr;
};
