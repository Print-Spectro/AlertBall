// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MySessionConfigurator.generated.h"

/**
 * 
 */

 class UWrapBox;
 class UMyLevelSelectButton;
 class UButton;

USTRUCT()
struct FLevelData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LevelData")
    FString LevelReference;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LevelData")
    FName LevelName = FName("Default Name");
 
    UPROPERTY(EditDefaultsOnly)
    UTexture2D* LevelImage;
};


UCLASS()
class ALERTBALL_API UMySessionConfigurator : public UUserWidget
{
	GENERATED_BODY()
    
    virtual void NativeConstruct() override;

public:
    UFUNCTION()
    void setCurrentLevel(const FLevelData Data);

protected:
    UPROPERTY(EditDefaultsOnly)
    const UDataTable* LevelTable;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UWrapBox* LevelWrapBox;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UButton* BTN_CreateSession;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UMyLevelSelectButton> SelectButtonTemplate;

    UPROPERTY(BlueprintReadOnly)
    FLevelData CurrentLevel;

    UPROPERTY(BlueprintReadOnly)
    int32 NumberofConnections = 6;

    UFUNCTION()
    void createLevelButtons();

    UFUNCTION()
    void createLevelButton(FLevelData Data);

    UFUNCTION()
    void onCreatePressed();

    
};


