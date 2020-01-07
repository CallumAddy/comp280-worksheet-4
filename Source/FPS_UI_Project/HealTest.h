// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealTest.generated.h"

UCLASS()
class FPS_UI_PROJECT_API AHealTest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealTest();

	UFUNCTION()
		void OnOverlap(AActor* MyOverlappedActor, AActor* OtherActor);

};
