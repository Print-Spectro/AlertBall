// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyCosmeticsWidget.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyTextureSelectButton.generated.h"

/**
 * 
 */

 class UButton;
 struct FTextureData;

UCLASS()
class ALERTBALL_API UMyTextureSelectButton : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

protected:
		
	UPROPERTY(BlueprintReadOnly, category = "WidgetBinding", meta = (BindWidget))
	UButton* BTN_Select;

	UPROPERTY(BlueprintReadOnly, category = "WidgetBinding", meta = (BindWidget))
	UTextBlock* TXT_Name;

	UPROPERTY()
	FTextureData ButtonData;

	UFUNCTION()
	void OnButtonPressed();

public:

	UFUNCTION()
	void setupButton(const FTextureData Data);

};
