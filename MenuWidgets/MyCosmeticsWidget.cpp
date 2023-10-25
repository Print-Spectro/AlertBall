// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCosmeticsWidget.h"

//widget binding
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "MyTextureSelectButton.h"

void UMyCosmeticsWidget::NativeConstruct()
{
	BTN_Skins->OnClicked.AddDynamic(this, &UMyCosmeticsWidget::onSkinsClicked);
	BTN_Head->OnClicked.AddDynamic(this, &UMyCosmeticsWidget::onHeadClicked);
	BTN_Knees->OnClicked.AddDynamic(this, &UMyCosmeticsWidget::onKneesClicked);
	addTextureButtons();
}

void UMyCosmeticsWidget::onSkinsClicked()
{
	WS_Cosmetics->SetActiveWidgetIndex(0);
}

void UMyCosmeticsWidget::onHeadClicked()
{
	WS_Cosmetics->SetActiveWidgetIndex(1);
}

void UMyCosmeticsWidget::onKneesClicked()
{
	WS_Cosmetics->SetActiveWidgetIndex(2);
}

void UMyCosmeticsWidget::addTextureButtons()
{
	if (TextureButtons.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("UMyCosmeticsWidget::addTextureButtons: Texture buttons array is empty"));
		return;
	}
	if (TextureButtonAsset == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("UMyCosmeticsWidget::addTextureButtons: No Button Asset selected to populate box"));
		return;
	}
	for (FTextureData i : TextureButtons) {
		UMyTextureSelectButton* TextureButton = CreateWidget<UMyTextureSelectButton>(GetWorld(), TextureButtonAsset);
		TextureButton->setupButton(i);
		TextureBox->AddChild(TextureButton);
	}
}
