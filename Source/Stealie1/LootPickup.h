// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "LootPickup.generated.h"

/**
 * 
 */
UCLASS()
class STEALIE1_API ALootPickup : public APickup
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALootPickup();
	
	void WasCollected_Implementation() override;
	
};
