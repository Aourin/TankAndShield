// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankController.generated.h"

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
};
