#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.h"
#include "SpawnVolume.generated.h"

/**
 * 
 */
UCLASS()
class POWERMAN5000_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:
	ASpawnVolume(const FObjectInitializer& ObjectInitializer);
	
	/** BoxComponent to specify the spawning area within the level */
	UPROPERTY(VisibleInstanceOnly, Category = Spawning)
	TSubobjectPtr<UBoxComponent> WhereToSpawn;

	/** The pickup to spawn */
	UPROPERTY(EditAnywhere, Category = Spawning)
	TSubclassOf<class APickup> WhatToSpawn;

	/** Minimum spawn delay. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
	float SpawnDelayRangeLow;

	/** Maximum spawn delay. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
	float SpawnDelayRangeHigh;

	/** Finds a random point within the BoxComponent. */
	UFUNCTION(BlueprintPure, Category = Spawning)
	FVector GetRandomPointInVolume();

	virtual void Tick(float DeltaSeconds);

	void EnableSpawning();

	void DisableSpawning();

private:

	/** Whether or not spawning is enabled */
	bool SpawningEnabled;

	/** Calculates a random spawn delay. */
	float GetRandomSpawnDelay();

	/** The current spawn delay. */
	float SpawnDelay;
	
	/** Handles the spawning of a new pickup. */
	void SpawnPickup();

	/** The timer for when to spawn the pickup */
	float SpawnTime;
};
