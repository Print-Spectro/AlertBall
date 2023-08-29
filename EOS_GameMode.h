// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EOS_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class ALERTBALL_API AEOS_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	//AEOS_GameMode();

private:	
	virtual void PostLogin(APlayerController* NewPlayer) override;


	
};
