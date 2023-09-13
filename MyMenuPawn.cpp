// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMenuPawn.h"
#include "Camera/CameraComponent.h"
#include "MyMainMenu.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyMenuPawn::AMyMenuPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//adding camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	//auto posses player zero
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyMenuPawn::BeginPlay()
{
	Super::BeginPlay();
	//createwidget

	//UMyMainMenu* UserInterface = CreateWidget<MainMenu>(GetWorld()->GetFirstPlayerController(), UMyMainMenu::StaticClass());
	//FInputModeUIOnly Mode;
	//Mode.SetLockMouseToViewport(true);
	//Mode.SetHideCursorDuringCapture(false);
	//SetInputMode(Mode);
	//UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//GetWorld()->GetFirstPlayerController()->SetInputMode(Mode);
	//UserInterface->AddToViewport(9999); // Z-order, this just makes it render on the very top.
}

// Called every frame
void AMyMenuPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyMenuPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

