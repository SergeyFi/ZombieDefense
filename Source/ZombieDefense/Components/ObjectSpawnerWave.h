// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "ZombieDefense/Components/ObjectSpawner.h"
#include "ObjectSpawnerWave.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UObjectSpawnerWave : public UObjectSpawner
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void OnSpawnedObjDestroy(AActor* DestroyedActor) override;

private:

	UPROPERTY(EditAnywhere)
	float WaveDelay;

	UPROPERTY(EditAnywhere)
	int SpawnCountNextWave;

	FTimerHandle TimerWaveDelay;

	void StartWaves();

	
	
};
