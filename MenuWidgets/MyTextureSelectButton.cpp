// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTextureSelectButton.h"

//widget components
#include "Components/Button.h"
#include "Components/TextBlock.h"

//include for FTextureData struct
#include "MyCosmeticsWidget.h"

//casting
#include "../MyUtility.h"
#include "../MyCharacterCPP.h"

void UMyTextureSelectButton::NativeConstruct()
{
	BTN_Select->OnClicked.AddDynamic(this, &UMyTextureSelectButton::OnButtonPressed);
}

void UMyTextureSelectButton::OnButtonPressed()
{
	UMyCosmeticsWidget* CosmeticsWidget = Cast<UMyCosmeticsWidget>(UMyUtility::GetCurrentWidget(this));
	if (CosmeticsWidget == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("UMyTextureSelectButton::OnButtonPressed: Cast to UMyCosmeticsWidget failed"));
		return;
	}

	AMyCharacterCPP* MenuPawn = UMyUtility::GetMenuPawn(this);
	if (MenuPawn == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("UMyTextureSelectButton::OnButtonPressed: MenuPawn is null"));
		return;
	}
	MenuPawn->GetMesh()->SetMaterial(0, ButtonData.Texture);

}

void UMyTextureSelectButton::setupButton(const FTextureData Data)
{
	ButtonData = Data;
	TXT_Name->SetText(FText::FromString(Data.TextureName));
	
}




