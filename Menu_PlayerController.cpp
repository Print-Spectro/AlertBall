// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu_PlayerController.h"
//widgets
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
//custom widgets
#include "MenuWidgets/MyBrowserWidget.h"
//widget switcher
#include "Components/WidgetSwitcher.h"
#include "MenuWidgets/MyMainMenuWidgetSwitch.h"

void AMenu_PlayerController::BeginPlay()
{
	Super::BeginPlay();


	if (MainMenuAsset != nullptr) {
		MenuSwitchInst = CreateWidget<UMyMainMenuWidgetSwitch>(GetWorld(), MainMenuAsset);

		MenuSwitchInst->AddToViewport();

		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(this);
		bShowMouseCursor = true;

		WidgetSwitcherInst = MenuSwitchInst->WidgetSwitcher;

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Menu Switcher Widget Selected"));
	}
}

void AMenu_PlayerController::SwitchMenu(float MenuIndex)
{
	if (WidgetSwitcherInst == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AMenu_PlayerController::SwitchMenu: WidgetSwitcher is null"))
		return;
	}
	if (WidgetSwitcherInst->GetNumWidgets() - 1 < MenuIndex) {
		UE_LOG(LogTemp, Warning, TEXT("AMenu_PlayerController::SwitchMenu: Index greater than number of widgets"))
		return;
	}
	WidgetSwitcherInst->SetActiveWidgetIndex(MenuIndex);
}

UMyBrowserWidget* AMenu_PlayerController::GetServerBrowser()
{
	if (WidgetSwitcherInst == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AMenu_PlayerController::GetServerBrowser: No WidgetSwitcher found"))
		return nullptr;
	}

	if (UMyBrowserWidget* BrowserWidget = Cast<UMyBrowserWidget>(WidgetSwitcherInst->GetActiveWidget())) {
		return BrowserWidget;
	}
	UE_LOG(LogTemp, Warning, TEXT("AMenu_PlayerController::GetServerBrowser: Cast to UMyBrowserWidget failed"))
	return nullptr;
	


	
}




