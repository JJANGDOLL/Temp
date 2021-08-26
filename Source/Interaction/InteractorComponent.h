// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"

class UCameraComponent;

USTRUCT()
struct FInteractableVariable
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY()
	float Dot;

	UPROPERTY()
	AActor* Interactor;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorComponent();

	UPROPERTY(VisibleAnywhere, Category = "Interactor")
	TArray<AActor*> Interactables;

	UPROPERTY(VisibleAnywhere, Category = "Interactor")
	AActor* BestInteractor;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interactor")
    UCameraComponent* InteractCamera;

	UFUNCTION(BlueprintCallable)
	void Initialize();

	UFUNCTION(BlueprintCallable)
	void RegisterInteraction(AActor* Interactor);

	UFUNCTION(BlueprintCallable)
	void UnregisterInteraction(AActor* Interactor);

	UFUNCTION()
	void SetBestInteraction(AActor* Interactor);

	UFUNCTION()
	void UpdateBestInteractor();

	UFUNCTION()
	void OnFocusInteractor();

	UFUNCTION()
	void OffFocusInteractor();

	UFUNCTION(BlueprintCallable)
	void DoInteraction();

public:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void BeginPlay() override;

};
