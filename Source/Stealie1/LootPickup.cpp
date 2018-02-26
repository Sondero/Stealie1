// Fill out your copyright notice in the Description page of Project Settings.

#include "LootPickup.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"

ALootPickup::ALootPickup() 
{
	GetMesh()->SetSimulatePhysics(true);

}

