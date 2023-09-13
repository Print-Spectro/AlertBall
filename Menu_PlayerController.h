// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Menu_PlayerController.generated.h"

/**
 * 
 */

 class UUserWidget;

UCLASS()
class ALERTBALL_API AMenu_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> MainMenuAsset;

	UPROPERTY()
	UUserWidget* MainMenuInst;
	

};
