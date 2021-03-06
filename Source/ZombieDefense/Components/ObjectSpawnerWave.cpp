// Copyright 2020 Sergey Firsov


#include "ObjectSpawnerWave.h"

void UObjectSpawnerWave::BeginPlay()
{
    Super::BeginPlay();

    StartWaves();
}

void UObjectSpawnerWave::OnSpawnedObjDestroy(AActor* DestroyedActor)
{
    --SpawnCurrent;

    if (SpawnCurrent <= 0)
    {
        SpawnCurrent = 0;

        SpawnCount += SpawnCountNextWave;

        StartWaves();
    }
}

void UObjectSpawnerWave::StartWaves()
{
    GetWorld()->GetTimerManager().SetTimer(TimerWaveDelay, this, &UObjectSpawnerWave::StartSpawn,
        WaveDelay, false, WaveDelay);
}
