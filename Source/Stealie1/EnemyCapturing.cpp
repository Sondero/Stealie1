// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCapturing.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Pickup.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"
#include "Stealie1Character.h"
#include "GameFramework/Character.h"


// Sets default values for this component's properties
UEnemyCapturing::UEnemyCapturing()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyCapturing::BeginPlay()
{
	Super::BeginPlay();

	PlayerCaughtState = CaptureDelay;
	
}


// Called every frame
void UEnemyCapturing::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Every tick, 
	if (GetOwner()->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn()) && PlayerCaughtState > -1)
	{
		PlayerCaughtState = PlayerCaughtState - 1;
		if (PlayerCaughtState == 0)
		{
			PlayerGetsCaught();
		}
	}
	else if (PlayerCaughtState > 0)
		PlayerCaughtState = CaptureDelay;
}

void UEnemyCapturing::PlayerGetsCaught()
{
	if (PlayerCaughtState == 0)
	{
		FVector PlayerLostLocation = { 10000.0f, 10000.0f, 10000.0f };
		UE_LOG(LogTemp, Warning, TEXT("You have been Caught!"))
		GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(PlayerLostLocation);
		PlayerCaughtState = -1;
	}
	
}