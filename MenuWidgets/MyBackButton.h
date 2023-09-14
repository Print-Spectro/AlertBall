// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyBackButton.generated.h"

/**
 * 
 */

 class UButton;

UCLASS()
class ALERTBALL_API UMyBackButton : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnButtonPressed();

protected: //allows blueprints to inherit properties
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Back;
};
