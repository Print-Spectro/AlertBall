// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBackButton.h"

//Button widget include
#include "Components/Button.h"

//Where code managers
#include "../Menu_PlayerController.h"
#include "../MyUtility.h"


void UMyBackButton::NativeConstruct()
{
	if (BTN_Back) 
	{
		BTN_Back->OnClicked.AddUniqueDynamic(this, &UMyBackButton::OnButtonPressed);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("UMyBackButton::NativeConstruct: No back button, likely using a cpp class instead of a blueprint"));
	}

}

//Switches to main menu
void UMyBackButton::OnButtonPressed()
{
	AMenu_PlayerController* PlayerController = UMyUtility::GetMenuPlayerController(this);
	PlayerController->SwitchMenu(0);
}
