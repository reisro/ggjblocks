// Fill out your copyright notice in the Description page of Project Settings.


#include "GameTimer.h"

// Sets default values
AGameTimer::AGameTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameTimer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameTimer::StartTimer()
{
	GameTimeFinishDel.BindUFunction(this, FName("FinishTimer"));
	GetWorldTimerManager().SetTimer(GameTimeFinishHandler, GameTimeFinishDel, gameDuration, false);

	if (OnGameTimerStarts.IsBound())
		OnGameTimerStarts.Broadcast();
}

void AGameTimer::FinishTimer()
{
	if (OnGameTimerEnds.IsBound())
		OnGameTimerEnds.Broadcast();
}

