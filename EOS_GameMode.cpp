// Fill out your copyright notice in the Description page of Project Settings.


#include "EOS_GameMode.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineSubsystem.h"
#include "Online/CoreOnline.h"

void AEOS_GameMode::PostLogin(APlayerController* NewPlayer)
{	
	Super::PostLogin(NewPlayer);
	if (NewPlayer)
	{
		FUniqueNetIdRepl UniqueNetIDRepl;
	}

}
