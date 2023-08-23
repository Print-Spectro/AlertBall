// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EOS_GameInstance.generated.h"


/**
 * 
 */
 class FUniqueNetId;

UCLASS()
class ALERTBALL_API UEOS_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "EOS Functions")
	void LoginWIthEOS(FString ID, FString Token, FString LoginType);

	UFUNCTION()
	void LoginWIthEOS_Return(int32 LocalUserNum, bool bWasSuccess, const FUniqueNetId& UserId, const FString& Error);
};
