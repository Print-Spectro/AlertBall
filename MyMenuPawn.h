//Immobile pawn used for menu camera positioning

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyMenuPawn.generated.h"

UCLASS()
class ALERTBALL_API AMyMenuPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyMenuPawn();

	class UCameraComponent* Camera;

	TSubclassOf<class UMyMainMenu> MainMenu;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
