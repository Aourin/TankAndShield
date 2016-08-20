// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAndShield.h"
#include "TankController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BEGIN PLAY"));
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank Controlled"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank is %s"), *(ControlledTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	FRotator HitRotator;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	HitLocation = FVector(1.0f);

	//	Get Viewport Sizes and Set Aim
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	//	Get ScreenPosition
	FVector2D ScreenPosition = FVector2D(ViewportSizeX * CrossHairLocation.X, ViewportSizeY * CrossHairLocation.Y);
	FVector LookDirection;

	if (GetLookDirection(ScreenPosition, LookDirection)) {
		FVector ActorLocation = GetPawn()->GetActorLocation();
		FVector AimPoint = ActorLocation * LookDirection * 500.f;

		DrawDebugLine(GetWorld(), ActorLocation, AimPoint, FColor::Red, false, -1.f, '\000', 10.f);
		//GetLookVectorHitLocation();
		return true;
	}
	else {
		return false;
	}

	
}

FVector ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection) const
{
	return LookDirection;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenPosition, FVector& LookDirection) const
{
	//	Get Location and Direction of Crosshair
	FVector WorldLocation;

	return DeprojectScreenPositionToWorld(
		ScreenPosition.X, 
		ScreenPosition.Y, 
		WorldLocation, 
		LookDirection
	);
}