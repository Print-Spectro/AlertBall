// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainMenu.h"
//components
#include "Components/Button.h"
#include "MyUtility.h"

//include player controller to call switch menu function. Could put this on the utility by why...
#include "Menu_PlayerController.h"


void UMyMainMenu::NativeConstruct()
{
    Super::NativeConstruct();

    // Bind delegates here.

    BTN_JoinGame->OnClicked.AddDynamic(this, &UMyMainMenu::OnBTN_JoinGamePressed);
    BTN_CreateGame->OnClicked.AddDynamic(this, &UMyMainMenu::OnBTN_CreateGamePressed);
    BTN_Cosmetics->OnClicked.AddDynamic(this, &UMyMainMenu::OnBTN_CosmeticsPressed);
    BTN_Settings->OnClicked.AddDynamic(this, &UMyMainMenu::OnBTN_SettingsPressed);
}

void UMyMainMenu::OnBTN_JoinGamePressed()
{
    UMyUtility::GetMenuPlayerController(this)->SwitchMenu(JoinSessionIndex);
}


void UMyMainMenu::OnBTN_CreateGamePressed()
{
    UMyUtility::GetMenuPlayerController(this)->SwitchMenu(CreateSessionIndex);
}

void UMyMainMenu::OnBTN_CosmeticsPressed()
{
    UMyUtility::GetMenuPlayerController(this)->SwitchMenu(CosmeticsIndex);
}

void UMyMainMenu::OnBTN_SettingsPressed()
{
    UMyUtility::GetMenuPlayerController(this)->SwitchMenu(SettingsIndex);
}
