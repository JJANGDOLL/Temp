// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Item.generated.h"

class UTuexture;

UENUM(Blueprintable, BlueprintType)
enum EItemType
{
    NONEITEMTYPE    UMETA(DisplayName = "None"),
    WEAPON          UMETA(DisplayName = "Weapon")
};

USTRUCT(Blueprintable, BlueprintType)
struct FItemInfo
{
    GENERATED_USTRUCT_BODY();

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemInfo")
    TEnumAsByte<EItemType> ItemType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FName ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    UTexture* ItemImage;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UItem : public UInterface
{
    GENERATED_BODY()
};

/**
 * 
 */
class INTERACTION_API IItem
{
    GENERATED_BODY()

    // Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Item")
    void GetItemInfo(FItemInfo& Item);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Item")
    void SetItemInfo();
};
