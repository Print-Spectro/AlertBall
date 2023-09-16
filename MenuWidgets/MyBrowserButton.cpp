// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBrowserButton.h"

//widget includes
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "MyBrowserWidget.h"

void UMyBrowserButton::NativeConstruct()
{
	Super::NativeConstruct();
	BTN_Server->OnClicked.AddDynamic(this, &UMyBrowserButton::onButtonPress);
}

void UMyBrowserButton::setupButton(const FName Occupancy, const FName OwningPlayer, const int32 SessionIndex)
{
	TXT_OwningPlayer->Text = FText::FromName(OwningPlayer);
	TXT_Occupancy->Text = FText::FromName(Occupancy);
	SessionToJoin = SessionIndex;
}

void UMyBrowserButton::onButtonPress()
{
	Cast<UMyBrowserWidget>(GetParent());

}
