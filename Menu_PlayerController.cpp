// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu_PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void AMenu_PlayerController::BeginPlay()
{
	Super::BeginPlay();


	if (MainMenuAsset != nullptr) {
		MainMenuInst = CreateWidget<UUserWidget>(GetWorld(), MainMenuAsset);
		MainMenuInst->AddToViewport();

		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(this);
		bShowMouseCursor = true;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Menu Asset Selected"));
	}
}
