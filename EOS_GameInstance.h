// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h" //include for EOnJoinSessionCompleteResult::Type
#include "EOS_GameInstance.generated.h"


/**
 * 
 */
 

UCLASS()
class ALERTBALL_API UEOS_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "EOS Functions")
	void LoginWIthEOS(FString ID, FString Token, FString LoginType);

	UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EOS Functions")
	FString getPlayerUsername();

	UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "EOS Functions")
	bool isPlayerLoggedIn();

	UFUNCTION(BlueprintCallable, Category="EOS Functions")
	void createEOSSession(bool bIsDedicatedServer, bool bIsLanServer, int32 NumberOfPublicConnections);

	UFUNCTION(BlueprintCallable, Category="EOS Functions")
	void findSesionAndJoin();

	UFUNCTION(BlueprintCallable, Category="EOS Functions")
	void joinSession();

	UFUNCTION(BlueprintCallable, Category="EOS Functions")
	void destroySession();

	//TSharedRef<FOnlineSessionSearch> SessionSearch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EOS Variables")
	FString OpenLevelText = FString("/Game/Levels/MainSessionMap");

	void onCreateSessionCompleted(FName SessionName, bool bWasSuccesful);
	void onDestroySessionCompleted(FName SessionName, bool bWasSuccesful);
	void LoginWIthEOS_Return(int32 LocalUserNum, bool bWasSuccess, const FUniqueNetId& UserId, const FString& Error);
	void onFindSessionCompleted(bool bWasSuccess);
	void OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result); //Include OnlineSessionInterface
		
};
