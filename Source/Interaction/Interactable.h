// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UMeshComponent;

class INTERACTION_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interact")
	void Interaction();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
	UMeshComponent* GetInteractableMesh();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interact")
	FVector GetCenterOfMass();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interact")
	void OnFocus();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
    void OffFocus();
};
