// Fill out your copyright notice in the Description page of Project Settings.


#include "EOS_GameInstance.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Online/CoreOnline.h"
#include "Kismet/GameplayStatics.h"


void UEOS_GameInstance::LoginWIthEOS(FString ID, FString Token, FString LoginType) {
	//Setting up online subsystem
	IOnlineSubsystem *SubsystemRef = Online::GetSubsystem(this->GetWorld());
	if (SubsystemRef == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Null found at subsystemref"));
		return;
	}
	IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface();
	if (IdentityPointerRef != nullptr) {
		FOnlineAccountCredentials AccountDetails;
		AccountDetails.Id = ID;
		AccountDetails.Token = Token;
		AccountDetails.Type = LoginType;
		IdentityPointerRef->OnLoginCompleteDelegates->AddUObject(this, &UEOS_GameInstance::LoginWIthEOS_Return);
		IdentityPointerRef->Login(0, AccountDetails);

	}
}


void UEOS_GameInstance::LoginWIthEOS_Return(int32 LocalUserNum, bool bWasSuccess, const FUniqueNetId& UserId, const FString& Error)
{
	if (bWasSuccess) {
		UE_LOG(LogTemp, Warning, TEXT("Login Success"));
	}
	if (!bWasSuccess) {
		UE_LOG(LogTemp, Error, TEXT("Login Fail Reason - %S"), *Error);
	}
}


FString UEOS_GameInstance::getPlayerUsername()
//Returns player username 
{
	IOnlineSubsystem* SubsystemRef = Online::GetSubsystem(this->GetWorld());
	if (SubsystemRef == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Null found at subsystemref"));
		return FString();
	}
	IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface();
	if (IdentityPointerRef == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Null found at IdentityPointer"));
		return FString();
	}
	if (IdentityPointerRef->GetLoginStatus(0) == ELoginStatus::LoggedIn) {
		return IdentityPointerRef->GetPlayerNickname(0);
	 }
	return FString();
	
}

bool UEOS_GameInstance::isPlayerLoggedIn()
{
	IOnlineSubsystem* SubsystemRef = Online::GetSubsystem(this->GetWorld());
	if (SubsystemRef == nullptr) {

		return 0;
	}
	IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface();
	if (IdentityPointerRef == nullptr) {
		
		return 0;
	}
	if (IdentityPointerRef->GetLoginStatus(0) == ELoginStatus::LoggedIn) {
		return 1;
	}
	return 0;
}

void UEOS_GameInstance::createEOSSession(bool bIsDedicatedServer, bool bIsLanServer, int32 NumberOfPublicConnections)
{
	IOnlineSubsystem* SubsystemRef = Online::GetSubsystem(this->GetWorld());
	if (SubsystemRef == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Null found at subsystemref"));
		return;
	}
	IOnlineSessionPtr SessionPtrRef = SubsystemRef->GetSessionInterface();
	if (SubsystemRef == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Null found at subsystemref"));
		return;
	}
	FOnlineSessionSettings SessionCreationInfo;
	SessionCreationInfo.bIsDedicated = bIsDedicatedServer;
	SessionCreationInfo.bAllowInvites = true;
	SessionCreationInfo.bIsLANMatch = bIsLanServer;
	SessionCreationInfo.NumPublicConnections = NumberOfPublicConnections;
	SessionCreationInfo.bUseLobbiesIfAvailable = true; //dedicated server doesn't support lobbies, use sessions / matchmaking 
	SessionCreationInfo.bUsesPresence = false;
	SessionCreationInfo.bShouldAdvertise = true;
	SessionCreationInfo.Set(SEARCH_KEYWORDS, FString("AngeloSearchSettingsMessage"), EOnlineDataAdvertisementType::ViaOnlineService);
	SessionPtrRef->OnCreateSessionCompleteDelegates.AddUObject(this, &UEOS_GameInstance::onCreateSessionCompleted);
	SessionPtrRef->CreateSession(0, FName("MainSession"), SessionCreationInfo);
}

void UEOS_GameInstance::onCreateSessionCompleted(FName SessionName, bool bWasSuccesful)
{
	if (!bWasSuccesful) {
		UE_LOG(LogTemp, Error, TEXT("UnableToCreateSession"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("SessionCreated"));
	GetWorld()->ServerTravel(OpenLevelText);

}



void UEOS_GameInstance::findSesionAndJoin()
{
}

void UEOS_GameInstance::onFindSessionCompleted(bool bWasSuccess)
{
}

void UEOS_GameInstance::joinSession()
{
}


void UEOS_GameInstance::OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}

void UEOS_GameInstance::destroySession()
{
	IOnlineSubsystem* SubsystemRef = Online::GetSubsystem(this->GetWorld());
	if (SubsystemRef == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Null found at subsystemref"));
		return;
	}
	IOnlineSessionPtr SessionPtrRef = SubsystemRef->GetSessionInterface();
	if (SessionPtrRef == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Null found at sessionptref"));
		return;
	}
	SessionPtrRef->OnDestroySessionCompleteDelegates.AddUObject(this, &UEOS_GameInstance::onDestroySessionCompleted);
	SessionPtrRef->DestroySession(FName("MainSession"));

}

void UEOS_GameInstance::onDestroySessionCompleted(FName SessionName, bool bWasSuccesful)
{
	if (bWasSuccesful) {
		UE_LOG(LogTemp, Verbose, TEXT("SessionDestroyed"));
	}
}