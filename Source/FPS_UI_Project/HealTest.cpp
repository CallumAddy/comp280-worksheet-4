// Fill out your copyright notice in the Description page of Project Settings.


#include "HealTest.h"
#include "FPS_UI_ProjectCharacter.h"

// Sets default values
AHealTest::AHealTest()
{

	OnActorBeginOverlap.AddDynamic(this, &AHealTest::OnOverlap);
}


	void AHealTest::OnOverlap(AActor * MyOverlappedActor, AActor * OtherActor)
	{
		
	}
