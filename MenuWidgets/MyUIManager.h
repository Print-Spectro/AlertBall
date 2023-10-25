//Unused, decided to manage UI on the player controller. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyUIManager.generated.h"

/**
 * 
 */

UCLASS()
class ALERTBALL_API UMyUIManager : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	UUserWidget* WidgetSwitch;
};
