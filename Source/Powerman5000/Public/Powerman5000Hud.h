#pragma once

#include "GameFramework/HUD.h"
#include "Powerman5000Hud.generated.h"

/**
 * 
 */
UCLASS()
class POWERMAN5000_API APowerman5000Hud : public AHUD
{
	GENERATED_BODY()

	APowerman5000Hud(const FObjectInitializer& ObjectInitializer);
	
	/** Variable for storing the font*/
	UPROPERTY()
	UFont* HUDFont;

	/** Primary draw call for the HUD */
	virtual void DrawHUD();
	
};
