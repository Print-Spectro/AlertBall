// Fill out your copyright notice in the Description page of Project Settings.


#include "EOS_GameMode.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineSubsystem.h"


void AEOS_GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if (NewPlayer)
	{
		FUniqueNetIdRepl UniqueNetIDRepl;
		if (NewPlayer->IsLocalController()) //check if player joining is the host
		{
			ULocalPlayer* LocalPlayerRef = NewPlayer->GetLocalPlayer();
			if (LocalPlayerRef) //Checking if there is a local player reference
			{
				UniqueNetIDRepl = LocalPlayerRef->GetPreferredUniqueNetId();
			}
			else //If there isn't a local player reference, cast to new player, get PlayerID
			{
				UNetConnection *RemoteNetConnectionRef = Cast<UNetConnection>(NewPlayer->Player);
				check(IsValid(RemoteNetConnectionRef));
				UniqueNetIDRepl = RemoteNetConnectionRef->PlayerId;
			}
		}
		else //Joining player is external 
		{
			UNetConnection *RemoteNetConnectionRef = Cast<UNetConnection>(NewPlayer->Player);
			check(IsValid(RemoteNetConnectionRef));
			UniqueNetIDRepl = RemoteNetConnectionRef->PlayerId;
		}
		TSharedPtr<const FUniqueNetId> UniqueNetId = UniqueNetIDRepl.GetUniqueNetId();
		if (UniqueNetId == nullptr) {
			return;
		}
		IOnlineSubsystem *SubsystemRef = Online::GetSubsystem(NewPlayer->GetWorld());
		IOnlineSessionPtr SessionRef = SubsystemRef->GetSessionInterface();
		bool bRegistrationSuccess = SessionRef->RegisterPlayer(FName("MainSession"), *UniqueNetId, false);
		if (bRegistrationSuccess) {
			UE_LOG(LogTemp, Warning, TEXT("Registration Successful"));
		}
	}
}

