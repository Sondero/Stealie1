// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorOpener.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEALIE1_API UDoorOpener : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorOpener();

	void OpenDoorUp();
	void OpenDoorRotate();

	void CountPickups();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	
	float PlayerStartMaxSpeed;
	
	float PlayerCurrentMaxSpeed;
	UPROPERTY(EditAnywhere)
	int RequiredPickups = 5;
	
	
	int CurrentPickups;

	bool DoorClosed = true;

	//These bools are there to make sure messages aren't spammed.
	bool DelayingVariableOne = 0;
	bool DelayingVariableTwo = 0;



private:
	UPROPERTY(EditAnywhere)
	float OpenMoveDistance = 200.0f;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 75.0f;

	//This should match the PickupModifier in Stealie1Character.h and Stealie1Character.cpp as well
	UPROPERTY(VisibleAnywhere)
		float PickupSpeedModifier = 0.95f;
	//This should match the PickupJumpModifier in Stealie1Character.h and Stealie1Character.cpp as well
	UPROPERTY(VisibleAnywhere)
		float PickupJumperModifier = 0.99f;
	
	//If DoorType is False, the door will rotate open, if doortype is true, the door will be moved open.
	UPROPERTY(EditAnywhere)
	bool DoorType = false;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	
	AActor* ActorThatOpens;
	AActor* Owner;
	

};
