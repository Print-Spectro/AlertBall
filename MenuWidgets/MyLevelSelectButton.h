// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//session configurator with struct
#include "MySessionConfigurator.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyLevelSelectButton.generated.h"

class UImage;
class UButton;
/**
 * 
 */

UCLASS()
class ALERTBALL_API UMyLevelSelectButton : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

	protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* IMG_LevelThumbnail;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Select;

	UPROPERTY(BlueprintReadOnly)
	FLevelData LevelData;

	public:

	void SetupButton(FLevelData Data);

	UFUNCTION()
	void OnButtonPressed();
};
