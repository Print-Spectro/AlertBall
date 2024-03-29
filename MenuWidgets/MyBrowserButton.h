// Button added to browser list to select the session

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyBrowserButton.generated.h"

/**
 * 
 */

class UTextBlock;
class UButton;
class FOnlineSessionSearchResult;

UCLASS()
class ALERTBALL_API UMyBrowserButton : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;
	
protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TXT_OwningPlayer;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TXT_Occupancy;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Server;

	UPROPERTY()
	int32 SessionToJoin;

public:

	UFUNCTION(BlueprintCallable)
	void setupButton(const FString Occupancy, const FString OwningPlayer, const int32 SessionIndex);

	UFUNCTION()
	void onButtonPress();
	
};
