// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Powerman5000.h"
#include "Powerman5000GameMode.h"
#include "Powerman5000Character.h"
#include "Powerman5000Hud.h"

APowerman5000GameMode::APowerman5000GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set the default HUD class
	HUDClass = APowerman5000Hud::StaticClass();

	// base decay rate
	DecayRate = 0.4f;

}

void APowerman5000GameMode::Tick(float DeltaSeconds)
{
	APowerman5000Character* MyCharacter = Cast<APowerman5000Character>(UGameplayStatics::GetPlayerPawn(this, 0));

	// if the character still has power
	if (MyCharacter->PowerLevel > 0.05)
	{
		// decrease the character's power
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.f, DeltaSeconds, DecayRate);
	}
	else
	{
		SetCurrentState(Powerman5000PlayState::GameOver);
	}

}

void APowerman5000GameMode::SetCurrentState(Powerman5000PlayState NewState)
{
	CurrentState = NewState;

	HandleNewState(NewState);

}
void APowerman5000GameMode::HandleNewState(Powerman5000PlayState NewState)
{

	switch (NewState)
	{
		// When we're playing, the spawn volumes can spawn
		case Powerman5000PlayState::Playing:
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->EnableSpawning();
			}
			break;

		// if the game is over, the spawn volumes should deactivate
		case Powerman5000PlayState::GameOver:
		{

			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->DisableSpawning();
			}
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
			PlayerController->SetCinematicMode(true, true, true);
			break;
		}

		case Powerman5000PlayState::Unknown:
			break;

		default:
			break;
	}

}

void APowerman5000GameMode::BeginPlay()
{
	Super::BeginPlay();

	// find all spawn volumes actors
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor)
		{
			SpawnVolumeActors.Add(SpawnVolumeActor);
		}
	}

	SetCurrentState(Powerman5000PlayState::Playing);
}
