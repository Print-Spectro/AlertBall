//Player controller used for the main menu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Menu_PlayerController.generated.h"

/**
 * 
 */

 class UUserWidget;
 class UWidgetSwitcher;
 class UMyMainMenuWidgetSwitch;
 class UMyBrowserWidget;

UCLASS()
class ALERTBALL_API AMenu_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, category = "Menu Widget")
	TSubclassOf<UUserWidget> MainMenuAsset;

public:

	UFUNCTION()
	void SwitchMenu(float MenuIndex);

	UFUNCTION()
	UWidget* getCurrentWidget();

	UFUNCTION()
	UMyBrowserWidget* GetBrowserWidget();

	UPROPERTY()
	UMyMainMenuWidgetSwitch* MenuSwitchInst;

	UPROPERTY()
	UWidgetSwitcher* WidgetSwitcherInst;
};
