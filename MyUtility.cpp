// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUtility.h"

#include "Menu_PlayerController.h"

APlayerController* UMyUtility::GetFirstPlayerController(UObject* Object)
{
	UWorld* World = Object->GetWorld();
	if (World == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetFirstPlayerController: No world found"));
		return nullptr;
	}
	if (APlayerController* PlayerController = World->GetFirstPlayerController()) {
		return PlayerController;
	}
	UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetFirstPlayerController: No player controller found"))
	return nullptr;
}

AMenu_PlayerController* UMyUtility::GetMenuPlayerController(UObject* Object) {

	AMenu_PlayerController* PlayerController = Cast<AMenu_PlayerController>(GetFirstPlayerController(Object));
	if (PlayerController == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetMenuPlayerController: No player controller found"));
		return nullptr;
	}
	return PlayerController;
}
