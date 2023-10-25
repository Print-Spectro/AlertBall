// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyBrowserWidget.generated.h"


/**
 * 
 */

 class UButton;
 class UScrollBox;
 class UMyBrowserButton;
 class FOnlineSessionSearchResult;
 class UUserWidget;

UCLASS()
class ALERTBALL_API UMyBrowserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	void setSessionToJoin(const int32 Index);

	void populateScrollBox(TArray<FOnlineSessionSearchResult> SessionsResults);

	void createSessionEntry(FOnlineSessionSearchResult SessionnResult, int32 index);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Join;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Refresh;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UScrollBox* ScrollBox;

	UPROPERTY(EditDefaultsOnly, category = "Menu Widget")
	TSubclassOf<UUserWidget> BrowserButtonAsset;

	UPROPERTY()
	int32 SessionToJoin;

	UFUNCTION()
	void onButtonPress();

	UFUNCTION()
	void onRefreshPress();
};
