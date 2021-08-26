// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HighlightComponent.generated.h"

class UMeshComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_API UHighlightComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHighlightComponent();

	UFUNCTION(BlueprintCallable, Category = "Highlight")
	void SetHighlight(UMeshComponent* myMesh);

	UFUNCTION(BlueprintCallable, Category = "Highlight")
	void UnsetHighlight(UMeshComponent* myMesh);
};
