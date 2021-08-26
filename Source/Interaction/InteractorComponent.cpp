// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractorComponent.h"
#include "Camera/CameraComponent.h"
#include "Interactable.h"
#include "Components/MeshComponent.h"
#include "Math/Vector.h"

// Sets default values for this component's properties
UInteractorComponent::UInteractorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInteractorComponent::Initialize()
{
    InteractCamera = GetOwner()->FindComponentByClass<UCameraComponent>();

    if(InteractCamera == nullptr)
        UE_LOG(LogTemp, Error, TEXT("Not  init"));
}

void UInteractorComponent::RegisterInteraction(AActor* Interactor)
{
    UClass* ActorClass = Interactor->GetClass();
    if (ActorClass->ImplementsInterface(UInteractable::StaticClass()))
    {
	    Interactables.Add(Interactor);
    }
}

void UInteractorComponent::UnregisterInteraction(AActor* Interactor)
{
	Interactables.Remove(Interactor);
}

void UInteractorComponent::SetBestInteraction(AActor* Interactor = nullptr)
{
    if (Interactor == nullptr)
    {
        if (BestInteractor != nullptr)
        {
            OffFocusInteractor();
            BestInteractor = nullptr;
        }
        return;
    }

    if(BestInteractor != Interactor)
    {
        if (BestInteractor != nullptr)
        {
            OffFocusInteractor();
        }

        BestInteractor = Interactor;
        OnFocusInteractor();
    }
}

void UInteractorComponent::UpdateBestInteractor()
{
    if (Interactables.Num() <= 0)
    {
        if (BestInteractor != nullptr)
        {
            IInteractable::Execute_OffFocus(BestInteractor);
        }
        BestInteractor = nullptr;
        return;
    }

    FInteractableVariable InteractableVar;
    InteractableVar.Dot = -1.0f;
    InteractableVar.Interactor = nullptr;
    for (AActor* Interactor : Interactables)
    {
        check(InteractCamera != nullptr);

        FVector CenterOfMesh = IInteractable::Execute_GetCenterOfMass(Interactor);
        FVector CameraWorldLocation = InteractCamera->GetComponentLocation();
        FVector CameraForwardVector = InteractCamera->GetForwardVector();

        FVector Temp = CenterOfMesh - CameraWorldLocation;
        Temp.Normalize(0.0001f);

        float DotVariable = FVector::DotProduct(Temp, CameraForwardVector);

        if (DotVariable > 0.0f && DotVariable > InteractableVar.Dot)
        {
            InteractableVar.Dot = DotVariable;
            InteractableVar.Interactor = Interactor;
        }
    }

    SetBestInteraction(InteractableVar.Interactor);
}

void UInteractorComponent::OnFocusInteractor()
{
    IInteractable::Execute_OnFocus(BestInteractor);
}

void UInteractorComponent::OffFocusInteractor()
{
    IInteractable::Execute_OffFocus(BestInteractor);
}

void UInteractorComponent::DoInteraction()
{
    if(BestInteractor != nullptr)
        IInteractable::Execute_Interaction(BestInteractor);
}

void UInteractorComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    UpdateBestInteractor();
}

void UInteractorComponent::BeginPlay()
{
    Super::BeginPlay();
    Initialize();
}

