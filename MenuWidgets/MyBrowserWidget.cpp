// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBrowserWidget.h"

//UI components
#include "Components/Button.h"
#include "Components/ScrollBox.h"

//custom UI classes
#include "MyBrowserButton.h"

//casting 
#include "../MyUtility.h"
#include "../EOS_GameInstance.h"


void UMyBrowserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	BTN_Join->OnClicked.AddDynamic(this, &UMyBrowserWidget::onButtonPress);
	BTN_Refresh->OnClicked.AddDynamic(this, &UMyBrowserWidget::onRefreshPress);
}

void UMyBrowserWidget::setSessionToJoin(const int32 Index)
{
	SessionToJoin = Index;
}


void UMyBrowserWidget::onButtonPress()
{
	
	UMyUtility::GetGameInstance(this)->joinSession(SessionToJoin);
}

void UMyBrowserWidget::onRefreshPress()
{
	UMyUtility::GetGameInstance(this)->findSessionAndJoin();
}

void UMyBrowserWidget::createSessionEntry(FOnlineSessionSearchResult SessionResult, int32 index)
{
	if (!BrowserButtonAsset) {
		UE_LOG(LogTemp, Error, TEXT("UMyBrowserWidget::createSessionEntry No BrowserButton Assigned"))
		return;
	}
	UMyBrowserButton* BrowserButton = CreateWidget<UMyBrowserButton>(GetWorld(), BrowserButtonAsset);

	//calculating occupancy
	int32 OpenConnections = SessionResult.Session.NumOpenPrivateConnections;
	int32 TotalConnections = SessionResult.Session.SessionSettings.NumPublicConnections;
	FString Occupancy = FString::Printf(TEXT("%i/%i"), TotalConnections-OpenConnections, TotalConnections);

	//get username
	FString Username = SessionResult.Session.OwningUserName;
	
	BrowserButton->setupButton(Occupancy, Username, index);
	ScrollBox->AddChild(BrowserButton);
}

void UMyBrowserWidget::populateScrollBox(TArray<FOnlineSessionSearchResult> SessionResults)
{
	ScrollBox->ClearChildren();
	int32 i = 0;
	for (FOnlineSessionSearchResult SessionResult : SessionResults) {
		createSessionEntry(SessionResult, i);
		i ++;
	}
}

