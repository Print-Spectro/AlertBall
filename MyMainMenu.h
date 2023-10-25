//Main Menu WIdget

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

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Settings;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_CreateGame;

	//widet switcher indexes for child widgets
	UPROPERTY(EditDefaultsOnly, Category = "ButtonAssignment", meta = (ToolTip = "Assign the index to switch to in the widget switcher"))
	float JoinSessionIndex = 1;

	UPROPERTY(EditDefaultsOnly, Category = "ButtonAssignment", meta = (ToolTip = "Assign the index to switch to in the widget switcher"))
	float CreateSessionIndex = 2;

	UPROPERTY(EditDefaultsOnly, Category = "ButtonAssignment", meta = (ToolTip = "Assign the index to switch to in the widget switcher"))
	float CosmeticsIndex = 3;

	UPROPERTY(EditDefaultsOnly, Category = "ButtonAssignment", meta = (ToolTip = "Assign the index to switch to in the widget switcher"))
	float SettingsIndex = 4;

	UFUNCTION()
	void OnBTN_JoinGamePressed();

	UFUNCTION()
	void OnBTN_CosmeticsPressed();

	UFUNCTION()
	void OnBTN_CreateGamePressed();

	UFUNCTION()
	void OnBTN_SettingsPressed();
};

