// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterCPP.h"
#include "UObject/ConstructorHelpers.h"

//input
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "MyInputConfigData.h"


//Actor components
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
AMyCharacterCPP::AMyCharacterCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = Mesh;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));//Creating spring arm
	SpringArmComp->SetupAttachment(Mesh);//Setting up attachment to the mesh


	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArmComp);
	//Allows orbital looking around
	
}

// Called when the game starts or when spawned
void AMyCharacterCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Get player controller
	APlayerController* PC = Cast<APlayerController>(GetController());

	// Get the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

	//Clear out existing mapping, and add our mapping
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	//Getting the EnhancedInputComponent
	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	//Binding the actions
	PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AMyCharacterCPP::Move);
	PEI->BindAction(InputActions->InputLook, ETriggerEvent::Triggered, this, &AMyCharacterCPP::Look);
	//PEI->BindAction(InputActions->InputJump, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	//PEI->BindAction(InputActions->InputJump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	
}	

void AMyCharacterCPP::Move(const FInputActionValue& Value) 
{	
	UE_LOG(LogTemp, Display, TEXT("MoveTriggered"));
	if (Controller != nullptr)
	{
		const FVector2D MoveValue = Value.Get<FVector2D>();
		const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);
		//Forward/Backward direction
		if (MoveValue.Y != 0.f)
		{
			//Get forward vector
			const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);

			AddMovementInput(Direction, MoveValue.Y);
		}

		//Right.Feft direction
		if (MoveValue.X != 0.f)
		{
			//Get right vector
			const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);

			AddMovementInput(Direction, MoveValue.X);

			//SetActorRotation(MovementRotation + FRotator(0,0, 0));
			
		}
		
	}
}

void AMyCharacterCPP::Look(const FInputActionValue& Value) 
{
	FVector2D LookValue = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		AddControllerYawInput(LookValue.X);
		AddControllerPitchInput(LookValue.Y);
	}
}

