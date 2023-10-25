//This utility class is used for repeat casting to ingame objects with error checking to prevent crashes.

#include "MyUtility.h"
#include "EOS_GameInstance.h"
#include "MyCharacterCPP.h"
#include "Menu_PlayerController.h"
#include "Kismet/GameplayStatics.h"

APlayerController* UMyUtility::GetFirstPlayerController(UObject* Object)
{
	UWorld* World = Object->GetWorld();
	if (World == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetFirstPlayerController: No world found"));
		return nullptr;
	}
	if (APlayerController* PlayerController = World->GetFirstPlayerController()) {
		return PlayerController;
	}
	UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetFirstPlayerController: No player controller found"))
	return nullptr;
}

AMenu_PlayerController* UMyUtility::GetMenuPlayerController(UObject* Object) {
	AMenu_PlayerController* PlayerController = Cast<AMenu_PlayerController>(GetFirstPlayerController(Object));
	if (PlayerController == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetMenuPlayerController: No player controller found"));
		return nullptr;
	}
	return PlayerController;
}

UEOS_GameInstance* UMyUtility::GetGameInstance(UObject* Object)
{
	UWorld* World = Object->GetWorld();
	if (World == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetGameInstance: No world found"));
		return nullptr;
	}
	UGameInstance* GameInstance = World->GetGameInstance();
	if (GameInstance == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetGameInstance: No Game Instance found"));
		return nullptr;
	}
	UEOS_GameInstance* EOSGameInstance = Cast<UEOS_GameInstance>(GameInstance);
	if (EOSGameInstance == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetGameInstance: Cast to EOS_GameInstance fail"));
		return nullptr;
	}
	return EOSGameInstance;
}

UMyBrowserWidget* UMyUtility::GetBrowserWidget(UObject* Object)
{
	return GetMenuPlayerController(Object)->GetBrowserWidget();
}

UWidget* UMyUtility::GetCurrentWidget(UObject* Object)
{
	return GetMenuPlayerController(Object)->getCurrentWidget();
}

AMyCharacterCPP* UMyUtility::GetMenuPawn(UObject* Object)
{
	UWorld* World = Object->GetWorld();
	if (World == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetMenuPawn: No world found"));
		return nullptr;
	}
	AMyCharacterCPP* MyCharacter = Cast<AMyCharacterCPP>(UGameplayStatics::GetActorOfClass(World, AMyCharacterCPP::StaticClass()));
	if (MyCharacter == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("UMyUtility::GetMenuPawn: Cast to Altert failed"));
		return nullptr;
	}
	return MyCharacter;
}


