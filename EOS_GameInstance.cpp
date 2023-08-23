// Fill out your copyright notice in the Description page of Project Settings.


#include "EOS_GameInstance.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystem.h"
#include "Online/CoreOnline.h"
#include "Interfaces/OnlineIdentityInterface.h"


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
	if (bWasSuccess) {
		UE_LOG(LogTemp, Error, TEXT("Login Fail Reason - %S"), *Error);
	}
}
