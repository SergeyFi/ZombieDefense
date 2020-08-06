// Copyright 2020 Sergey Firsov


#include "ObjectSpawnerWave.h"

void UObjectSpawnerWave::BeginPlay()
{
    Super::BeginPlay();

    WaveDelayed();
}

void UObjectSpawnerWave::OnSpawnedObjDestroy(AActor* DestroyedActor)
{
    --SpawnCurrent;

    if (SpawnCurrent <= 0)
    {
        SpawnCurrent = 0;

        WaveDelayed();
    }
}

void UObjectSpawnerWave::WaveDelayed()
{
    GetWorld()->GetTimerManager().SetTimer(TimerWaveDelay, this, &UObjectSpawnerWave::StartSpawn,
        WaveDelay, false, WaveDelay);
}
