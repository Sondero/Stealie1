// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorOpener.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Stealie1Character.h"
#include <cmath>
#include "Stealie1Character.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "Pickup.h"

// Sets default values for this component's properties
UDoorOpener::UDoorOpener()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpener::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner(); ///Gets The Owner, which is the door in this case

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	//Gets the Max Speed the Player has
	PlayerStartMaxSpeed = GetWorld()->GetFirstPlayerController()->GetPawn()->GetMovementComponent()->GetMaxSpeed();

}




// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (DoorClosed == true) //This if statement makes sure the Door is closed before it goes through the opening process.
	{
		if (PressurePlate->IsOverlappingActor(ActorThatOpens)) //Asks if the player is overlapping the pressure plate.
		{
			CountPickups();
			if (CurrentPickups > RequiredPickups - 1) //checks to make sure the player has collected enough pickups
			{
				if (DoorType == false) //determines how the door opens, whether it slides upward/downward or rotates open.
					OpenDoorRotate();
				else if (DoorType == true)
					OpenDoorUp();
			}
			else if (DelayingVariableTwo == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("You must collect %i Pickups to activate this pressure plate."), RequiredPickups)
				DelayingVariableTwo = 1;
			}
		}
		else //Bools that updates the pressure plate resets once the player steps off it.
		{
			DelayingVariableOne = 0;
			DelayingVariableTwo = 0;
		}
	}
	// ...
}

//Here the door makes sure that the player has collected enough pickups. It uses 
void UDoorOpener::CountPickups()
{
	if (DelayingVariableOne == 0)
	{



		PlayerCurrentMaxSpeed = GetWorld()->GetFirstPlayerController()->GetPawn()->GetMovementComponent()->GetMaxSpeed();
		//PlayerCurrentMaxJump = AStealie1Character::GetCharacterMovement()->JumpZVelocity;

	CurrentPickups = (int) floor(0.5f - ((logf(PlayerStartMaxSpeed) / logf(PickupSpeedModifier)) -
		(logf(PlayerCurrentMaxSpeed) / logf(PickupSpeedModifier))));
	
		UE_LOG(LogTemp, Warning, TEXT("You have collected %i pickups"), CurrentPickups)
		DelayingVariableOne = 1;
	}
}

void UDoorOpener::OpenDoorUp()
{
	FVector ClosedLocation = Owner->GetActorLocation();
	FVector NewLocation = { 0.0f, 0.0f, OpenMoveDistance };

	Owner->SetActorLocation(ClosedLocation+NewLocation);
	DoorClosed = false;
}

void UDoorOpener::OpenDoorRotate()
{
	FRotator NewRotation = FRotator(0.0f, OpenAngle, 0.0f);

	Owner->SetActorRotation(NewRotation);

	DoorClosed = false;
}