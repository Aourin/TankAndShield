// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Booster.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKANDSHIELD_API UBooster : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float BoostForce = 33000.f;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetThrottle(float Throttle);
};
