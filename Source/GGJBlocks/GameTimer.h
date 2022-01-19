// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameTimer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStarts);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameEnds);

UCLASS()
class GGJBLOCKS_API AGameTimer : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Game")
	float gameDuration = 5.0f;
	
	UPROPERTY(BlueprintAssignable, Category="Game")
	FOnGameStarts OnGameTimerStarts;

	UPROPERTY(BlueprintAssignable, Category="Game")
	FOnGameEnds OnGameTimerEnds;

	FTimerDelegate GameTimeFinishDel;
	FTimerHandle GameTimeFinishHandler;

	// Constructor
	AGameTimer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartTimer();

	UFUNCTION(BlueprintCallable)
	void FinishTimer();
};
