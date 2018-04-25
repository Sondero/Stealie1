// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraActorCode.h"
#include "Components/ActorComponent.h"
#include "Engine/ActorChannel.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"


// Sets default values for this component's properties
UCameraActorCode::UCameraActorCode()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UCameraActorCode::BeginPlay()
{
	Super::BeginPlay();
	

}


// Called every frame
void UCameraActorCode::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(); ///Gets the Location of the Player.
	GetOwner()->SetActorLocation(PlayerLocation + CameraDistance);///Sets the location of the camera to a certain point above and behind the character.

	if (PlayerLocation.Z < 0.0f) ///This is a Failsafe that makes sure UE4 doesn't crash if the character falls OoB.
	{
		GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FailSafeLocation);
	}

	if (WinBox->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
		GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(VictoryLocation);
	}

}