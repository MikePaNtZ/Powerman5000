// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class POWERMAN5000_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:
	ABatteryPickup(const FObjectInitializer& ObjectInitializer);

	/// - Set the amount of power the battery gives to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float PowerLevel;

	/// - This overrided the OnPickedUp function
	void OnPickedUp_Implementation();
	
};
