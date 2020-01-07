// Fill out your copyright notice in the Description page of Project Settings.


#include "PointOfInterest_Component.h"

// Sets default values for this component's properties
UPointOfInterest_Component::UPointOfInterest_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPointOfInterest_Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GetWorld()->GetTimerManager().SetTimer(Delay, this, &UPointOfInterest_Component::OnTimerEnd, 0.2f, false);
}


// Called every frame
void UPointOfInterest_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPointOfInterest_Component::OnTimerEnd()
{
}

