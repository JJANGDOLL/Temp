// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteractor.h"
#include "Components/MeshComponent.h"

// Sets default values
ABaseInteractor::ABaseInteractor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABaseInteractor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseInteractor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

