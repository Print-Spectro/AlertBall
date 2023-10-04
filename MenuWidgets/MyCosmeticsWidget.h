// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCosmeticsWidget.generated.h"

/**
 * 
 */

class UButton;
class UWidgetSwitcher;
class UTextBlock;
class UMyTextureSelectButton;
class UScrollBox;

USTRUCT()
struct ALERTBALL_API FTextureData
 {
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* Texture;

	UPROPERTY(EditDefaultsOnly)
	FString TextureName;
 };


UCLASS()
class ALERTBALL_API UMyCosmeticsWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

protected:
	
	UPROPERTY(BlueprintReadOnly, category = "buttons", meta = (BindWidget))
	UButton* BTN_Skins;

	UPROPERTY(BlueprintReadOnly, category = "buttons", meta = (BindWidget))
	UButton* BTN_Head;

	UPROPERTY(BlueprintReadOnly, category = "buttons", meta = (BindWidget))
	UButton* BTN_Knees;

	UPROPERTY(BlueprintReadOnly, category = "buttons", meta = (BindWidget))
	UWidgetSwitcher* WS_Cosmetics;

	UPROPERTY(BlueprintReadOnly, category = "buttons", meta = (BindWidget))
	UScrollBox* TextureBox;

	UPROPERTY(EditDefaultsOnly, category = "buttons")
	TArray<FTextureData> TextureButtons;

	UPROPERTY(EditDefaultsOnly, category = "buttons")
	TSubclassOf<UMyTextureSelectButton> TextureButtonAsset;

	UFUNCTION()
	void onSkinsClicked();

	UFUNCTION()
	void onHeadClicked();

	UFUNCTION()
	void onKneesClicked();

	UFUNCTION()
	void addTextureButtons();

};
