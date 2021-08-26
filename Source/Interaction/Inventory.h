// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Inventory")
	int InventorySize;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
