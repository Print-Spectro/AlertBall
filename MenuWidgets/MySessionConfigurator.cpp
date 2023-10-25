//Widget for configuring and creating multiplayer sessions


#include "MySessionConfigurator.h"
#include "Components/WrapBox.h"
#include "MyLevelSelectButton.h"

//Casting for functionality 
#include "../MyUtility.h"
#include "../EOS_GameInstance.h"

//Widget binding
#include "Components/Button.h"

void UMySessionConfigurator::NativeConstruct()
{
	BTN_CreateSession->OnClicked.AddUniqueDynamic(this, &UMySessionConfigurator::onCreatePressed);
	createLevelButtons();
}


void UMySessionConfigurator::createLevelButtons()
{
	TArray<FLevelData*> DataRows;
	if (LevelTable == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMySessionConfigurator::createLevelButtons: No LevelTable"));
		return;
	}
	LevelTable->GetAllRows(TEXT("OptionalContext"), DataRows);
	if (DataRows.Num() == 0) {
		UE_LOG(LogTemp, Error, TEXT("UMySessionConfigurator::createLevelButtons: Data Table is empty"));
		return;
	}
	for (FLevelData* Row : DataRows) {
		createLevelButton(*Row);
	}
	setCurrentLevel(*DataRows[0]);
}

void UMySessionConfigurator::createLevelButton(FLevelData Data)
{
	if (SelectButtonTemplate == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMySessionConfigurator::createLevelButton: no button template selected"));
		return;
	}
	if (!SelectButtonTemplate->IsChildOf(UMyLevelSelectButton::StaticClass())) {
		UE_LOG(LogTemp, Error, TEXT("UMySessionConfigurator::createLevelButton: Button template has incorrect type"));
		return;
	}
	UMyLevelSelectButton* LevelButton = CreateWidget<UMyLevelSelectButton>(GetWorld(), SelectButtonTemplate);
	LevelButton->SetupButton(Data);
	LevelWrapBox->AddChildToWrapBox(LevelButton);
}


void UMySessionConfigurator::setCurrentLevel(const FLevelData Data)
{
	CurrentLevel = Data;
	UMyUtility::GetGameInstance(this)->setLevelReference(CurrentLevel.LevelReference);
}

void UMySessionConfigurator::onCreatePressed()
{
	UMyUtility::GetGameInstance(this)->createEOSSession(false, false, NumberofConnections);
}