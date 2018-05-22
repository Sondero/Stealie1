// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraActorCode.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEALIE1_API UCameraActorCode : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraActorCode();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)
	FVector CameraDistance = { -300.0f, 0.0f, 500.0f };
	
	UPROPERTY(EditAnywhere)
	FVector FailSafeLocation = { -1660.0f, 1160.0f, 236.0f };

	/*UPROPERTY(EditAnywhere)
	ATriggerVolume* WinBox;

	UPROPERTY(EditAnywhere)
	FVector WinLocation = { 10000.0f, 4360.0f, 10000.0f };*/

private:
	/* GetNextLevel();

	UPROPERTY(EditAnywhere)
	ULevel* NextLevel;*/
};
