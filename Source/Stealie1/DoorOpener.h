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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
	UPROPERTY(EditAnywhere)
	float OpenMoveDistance = 200.0f;

	UPROPERTY(EditAnywhere)
	float OpenAngle = -75.0f;
	
	//If DoorType is False, the door will rotate open, if doortype is true, the door will be moved open.
	UPROPERTY(EditAnywhere)
	bool DoorType = false;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	AActor * ActorThatOpens;
};
