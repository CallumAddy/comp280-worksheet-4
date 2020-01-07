// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FPS_UI_ProjectGameMode.h"
#include "FPS_UI_ProjectHUD.h"
#include "Kismet/GameplayStatics.h"
#include "FPS_UI_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPS_UI_ProjectGameMode::AFPS_UI_ProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPS_UI_ProjectHUD::StaticClass();
}

void AFPS_UI_ProjectGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGameState::EPlaying);

	Player = Cast<AFPS_UI_ProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AFPS_UI_ProjectGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Player)
	{
		if (FMath::IsNearlyZero(Player->GetHealth(), 0.001f))
		{
			SetCurrentState(EGameState::EGameOver);
		}
	}
}

EGameState AFPS_UI_ProjectGameMode::GetCurrentState() const
{
	return currentState;
}

void AFPS_UI_ProjectGameMode::SetCurrentState(EGameState NewState)
{
	currentState = NewState;
	HandleNewState(currentState);
}

void AFPS_UI_ProjectGameMode::HandleNewState(EGameState newState)
{
	switch (newState)
	{
	case EGameState::EPlaying:
		break;
	case EGameState::EGameOver:
		UGameplayStatics::OpenLevel(this, FName(*GetLevel()->GetName()), false);
		break;
	case EGameState::EPaused:
		break;
	case EGameState::EMainMenu:
		UGameplayStatics::OpenLevel(this, FName("MainMenu", false));
		break;
	}
}




