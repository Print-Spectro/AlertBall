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
	//Adding main menu widget to the player viewport 
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

//Allows for switching to child widgets of the widget switcher
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

//This returns the browser widget only if the active widget is the browser
UMyBrowserWidget* AMenu_PlayerController::GetBrowserWidget()
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

//Can return any of the widget switcher child widgets, but casting will be needed to access subclasses
UWidget* AMenu_PlayerController::getCurrentWidget()
{
	if (WidgetSwitcherInst == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AMenu_PlayerController::GetServerBrowser: No WidgetSwitcher found"))
			return nullptr;
	}
	if (UWidget* BrowserWidget = WidgetSwitcherInst->GetActiveWidget()) 
	{
		return BrowserWidget;
	}
	UE_LOG(LogTemp, Warning, TEXT("AMenu_PlayerController::GetServerBrowser: Cast to UMyBrowserWidget failed"))
		return nullptr;
}





