// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyBrowserWidget.generated.h"

/**
 * 
 */

 class UButton;


UCLASS()
class ALERTBALL_API UMyBrowserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

	UFUNCTION()
	void setSessionToJoin(const int32 Index);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Join;

	UPROPERTY()
	int32 SessionToJoin;

	UFUNCTION()
	void onButtonPress();





};
