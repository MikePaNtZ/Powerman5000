// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Powerman5000.h"
#include "Powerman5000GameMode.h"
#include "Powerman5000Character.h"

APowerman5000GameMode::APowerman5000GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
