#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class POWERMAN5000_API APickup : public AActor
{
	GENERATED_BODY()

public:
	APickup(const FObjectInitializer& ObjectInitializer);

	/// - Power up active variable. True when power up active, false when power up de-activated.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	bool isActive;
	
	/// - Simple collision primitive to use as the root component.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
	TSubobjectPtr<USphereComponent> BaseCollisionComponent;
	
	/// - StatichMeshComponent to represent the pickup in the level.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
	TSubobjectPtr<UStaticMeshComponent> PickupMesh;

	/// - Function called whn the Pickup is collected
	UFUNCTION(BlueprintNativeEvent)
	void OnPickedUp();
};
