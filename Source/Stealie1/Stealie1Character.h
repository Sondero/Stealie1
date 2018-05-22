// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Stealie1Character.generated.h"

UCLASS(config = Game)
class AStealie1Character : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;*/

		/** Follow camera */
		/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;*/

		/** Collection Sphere */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CollectionSphere;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CaughtSphere;


public:
	AStealie1Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	//This should match the PickupModifier in DoorOpener.h and DoorOpener.cpp and the Get text 0 in the HUD Blueprint as well
	UPROPERTY(VisibleAnywhere)
		float PickupModifier = 0.95f;
	//This should match the PickupJumpModifier in DoorOpener.h and DoorOpener.cpp as well
	UPROPERTY(VisibleAnywhere)
		float PickupJumpModifier = 0.99f;

	UPROPERTY(EditAnywhere)
		FVector PickupScaleModifier = { 2.5f , 2.5f , 2.5f };

	float NewScaleX;
	float NewScaleY;
	float NewScaleZ;

	UPROPERTY(EditAnywhere)
		FVector PickupScaleCap = { 500.0f, 500.0f , 500.0f };

	//UPROPERTY(EditAnywhere)
	//USkeletalMeshComponent* VisibleMeshComponent;

protected:


	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void CollectPickups();

public:

	//
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }


	/** Returns CameraBoom subobject
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }**/
	//Returns FollowCamera subobject
	//FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/*
	public:
	//Protects the game from crashing. If the character falls to a certain distance down,
	//he will respawn at a set location
	void FailSafe(float DeltaTime);
	UPROPERTY(VisibleAnywhere)
	FVector FailSafeLocation = { 0.0f, 0.0f, 100.0f }; */ ///Doesn't seem to be working properly here
};

