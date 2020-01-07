// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS_UI_ProjectCharacter.h"
#include "FPS_UI_ProjectGameMode.generated.h"

UENUM()
enum class EGameState
{
	EPlaying,
	EPaused,
	EGameOver,
	EMainMenu
};
UCLASS(minimalapi)
class AFPS_UI_ProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPS_UI_ProjectGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AFPS_UI_ProjectCharacter* Player;

	UFUNCTION(BlueprintPure, Category = "GameState")
		EGameState GetCurrentState() const;

	void SetCurrentState(EGameState NewState);

private:
	EGameState currentState;

	void HandleNewState(EGameState newState);



};



