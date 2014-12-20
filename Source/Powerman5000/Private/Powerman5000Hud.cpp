// Fill out your copyright notice in the Description page of Project Settings.

#include "Powerman5000.h"
#include "Powerman5000Hud.h"
#include "Powerman5000GameMode.h"
#include "Powerman5000Character.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Kismet/GameplayStatics.h"

APowerman5000Hud::APowerman5000Hud(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	// Use the RobotoDistanceField font from the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}

void APowerman5000Hud::DrawHUD()
{
	// Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	// Call to the parent version of DrawHUD
	Super::DrawHUD();

	// Get the character and print its power level
	APowerman5000Character* MyCharacter = Cast<APowerman5000Character>(UGameplayStatics::GetPlayerPawn(this, 0));
	FString PowerLevelString = FString::Printf(TEXT("%10.1f"), FMath::Abs(MyCharacter->PowerLevel));
	DrawText(PowerLevelString, FColor::White, 50, 50, HUDFont);

	APowerman5000GameMode* MyGameMode = Cast<APowerman5000GameMode>(UGameplayStatics::GetGameMode(this));

	// if the game is over
	if (MyGameMode->GetCurrentState() == Powerman5000PlayState::GameOver)
	{
		// create a variable for storing the size of printing game over.
		FVector2D GameOverSize;
		GetTextSize(TEXT("GAME OVER"), GameOverSize.X, GameOverSize.Y, HUDFont);
		DrawText(TEXT("GAME OVER"), FColor::White, (ScreenDimensions.X - GameOverSize.X) / 2.0f, (ScreenDimensions.Y - GameOverSize.Y) / 2.0f, HUDFont);
	}
}



