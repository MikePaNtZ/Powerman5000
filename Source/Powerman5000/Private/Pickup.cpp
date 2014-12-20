// Fill out your copyright notice in the Description page of Project Settings.

#include "Powerman5000.h"
#include "Pickup.h"

APickup::APickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	// The pickup is valied when it is created.
	isActive = true;

	// Create the root SphereComponent to handle the pickup's collision.
	BaseCollisionComponent = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	// Set the SphereComponent as the root component
	RootComponent = BaseCollisionComponent;

	// Create the static mesh component
	PickupMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	// Turn physics on for the static mesh
	PickupMesh->SetSimulatePhysics(true);

	// Attach the static mesh component to root component
	PickupMesh->AttachTo(RootComponent);

}

void APickup::OnPickedUp_Implementation()
{

}



