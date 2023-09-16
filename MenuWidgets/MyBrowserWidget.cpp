// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBrowserWidget.h"
#include "Components/Button.h"
#include "../MyUtility.h"
#include "../EOS_GameInstance.h"

void UMyBrowserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	BTN_Join->OnClicked.AddDynamic(this, &UMyBrowserWidget::onButtonPress);
}

void UMyBrowserWidget::setSessionToJoin(const int32 Index)
{
	SessionToJoin = Index;
}

void UMyBrowserWidget::onButtonPress()
{
	UMyUtility::GetGameInstance(this)->joinSession(SessionToJoin);
}
