// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputActionValue.h"

#include "MyCharacterCPP.generated.h"


/* 
Custom class that handles movement and interaction

*/

UCLASS()
class ALERTBALL_API AMyCharacterCPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// 	UPROPERTY(EditDefaultsOnly)
// 	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* ThirdPersonCamera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UPROPERTY(BlueprintReadWrite)
	//UTimelineComponent* MyTimeline;

	UPROPERTY(EditAnywhere, Category = "Curve")
	UCurveFloat* MyCurve;

	float CurveValue;


#pragma region /** Input */
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UMyInputConfigData* InputActions;

// 	UPROPERTY(EditDefaultsOnly)
// 	class UCharacterMovementComponent* CharacterMovement;

	//Handle move input
	void Move(const FInputActionValue& Value);

	//Handle Look input 
	void Look(const FInputActionValue& Value);

	//Stop moving when move input released
	void stopMove(const FInputActionValue& Value);

	
	//Handle Jump input 
	//void Jump(const FInputActionValue& Value);
	
	UPROPERTY(EditDefaultsOnly)
	float MoveSpeed = 100;

	UPROPERTY()
	bool ShouldMove = false;
	
	UPROPERTY()
	FVector MoveDirection;
};

