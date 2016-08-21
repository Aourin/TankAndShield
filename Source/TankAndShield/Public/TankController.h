// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/PlayerController.h"
#include "TankController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class TANKANDSHIELD_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;

	UPROPERTY(EditAnywhere)
	FVector2D CrossHairLocation;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000.f;

	void AimTowardsCrosshair();

private:
	
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitResult) const;
	bool GetLookDirection(FVector2D ScreenPosition, FVector& LookDirection) const;
};
