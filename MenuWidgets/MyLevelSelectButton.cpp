//Button created from data table that determines the level and the thumbnail

#include "MyLevelSelectButton.h"

//uwidgets
#include "Components/Image.h"
#include "Components/Button.h"

//casting
#include "../Menu_PlayerController.h"
#include "../MyUtility.h"

//session setup widget for FLevelData and other functions and stuff
#include "MySessionConfigurator.h"


void UMyLevelSelectButton::NativeConstruct()
{
	if (BTN_Select == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyLevelSelectButton::NativeConstruct: Button is nullptr"));
		return;
	}
	BTN_Select->OnClicked.AddUniqueDynamic(this, &UMyLevelSelectButton::OnButtonPressed);
}

void UMyLevelSelectButton::SetupButton(FLevelData Data)
{
	LevelData = Data;
	if (IMG_LevelThumbnail == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyLevelSelectButton::SetupButton: IMG_LevelThumbnail is nullptr"));
		return;
	}
	IMG_LevelThumbnail->SetBrushFromTexture(Data.LevelImage);
}

void UMyLevelSelectButton::OnButtonPressed()
{
	if (UMySessionConfigurator* SessoinConfig = Cast<UMySessionConfigurator>(UMyUtility::GetCurrentWidget(this))) {
		SessoinConfig->setCurrentLevel(LevelData);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("UMyLevelSelectButton::OnButtonPressed: Cast to session config failed"));
	}
	
}