// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyUtility.generated.h"

/**
 * 
 */
 class AMenu_PlayerController;
 class UEOS_GameInstance;
 class UMyBrowserWidget;

UCLASS()
class ALERTBALL_API UMyUtility : public UObject
{
	GENERATED_BODY()
	
public:
	
	static APlayerController* GetFirstPlayerController(UObject* Object);
	static AMenu_PlayerController* GetMenuPlayerController(UObject* Object);
	static UEOS_GameInstance* GetGameInstance(UObject* Object);
	static UMyBrowserWidget* GetBrowserWidget(UObject* Object);
};
