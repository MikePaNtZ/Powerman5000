// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "SpawnVolume.h"
#include "Powerman5000GameMode.generated.h"

enum class Powerman5000PlayState : short
{
	Playing,
	GameOver,
	Unknown
};

UCLASS(minimalapi)
class APowerman5000GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	APowerman5000GameMode(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaSeconds);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Power)
	float DecayRate;

	Powerman5000PlayState GetCurrentState() const;

	void SetCurrentState(Powerman5000PlayState NewState);

	virtual void BeginPlay();

private:

	TArray<ASpawnVolume*> SpawnVolumeActors;

	void HandleNewState(Powerman5000PlayState NewState);

	Powerman5000PlayState CurrentState;

};

FORCEINLINE Powerman5000PlayState APowerman5000GameMode::GetCurrentState() const
{
	return CurrentState;
}



