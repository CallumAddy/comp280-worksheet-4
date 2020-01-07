// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTest.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ADamageTest::ADamageTest()
{
	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	boxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = boxComponent;

	Fire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("My Fire"));
	Fire->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Fire->SetupAttachment(RootComponent);

	boxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADamageTest::OnOverlapBegin);
	boxComponent->OnComponentEndOverlap.AddDynamic(this, &ADamageTest::OnOverlapEnd);

}

void ADamageTest::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bCanApplyDamage = true;
		Player = Cast<AActor>(OtherActor);
		hit = SweepResult;
		GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ADamageTest::ApplyFireDamage, 2.2f, true, 0.0f);
	}
}

void ADamageTest::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bCanApplyDamage = false;
	GetWorldTimerManager().ClearTimer(FireTimerHandle);
}

void ADamageTest::ApplyFireDamage()
{
	if (bCanApplyDamage)
	{
		UGameplayStatics::ApplyPointDamage(Player, 200.0f, GetActorLocation(), hit, nullptr, this, FireDamageType);
	}
}
