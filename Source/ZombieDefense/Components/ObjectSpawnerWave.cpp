// Copyright 2020 Sergey Firsov


#include "ObjectSpawnerWave.h"

void UObjectSpawnerWave::BeginPlay()
{
    Super::BeginPlay();

    WaveInit();
}

void UObjectSpawnerWave::WaveInit()
{
    GetWorld()->GetTimerManager().SetTimer(TimerInitial, this, &UObjectSpawnerWave::StartWaves,
        WaveItitialDelay, false, WaveItitialDelay);
}

void UObjectSpawnerWave::StartWaves()
{
    GetWorld()->GetTimerManager().SetTimer(TimerWave, this, &UObjectSpawnerWave::StartSpawn, WaveDelay, true);
}

void UObjectSpawnerWave::StartWave()
{
    StartSpawn();
}
