// Fill out your copyright notice in the Description page of Project Settings.

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
