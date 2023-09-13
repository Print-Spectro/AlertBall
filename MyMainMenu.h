// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyMainMenu.generated.h"

/**
 * 
 */

 class UButton;
UCLASS()
class ALERTBALL_API UMyMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

	protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_JoinGame ;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Cosmetics;
};

