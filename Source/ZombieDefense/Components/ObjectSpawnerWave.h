// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "ZombieDefense/Components/ObjectSpawner.h"
#include "ObjectSpawnerWave.generated.h"


UCLASS()
class ZOMBIEDEFENSE_API UObjectSpawnerWave : public UObjectSpawner
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void OnSpawnedObjDestroy(AActor* DestroyedActor) override;

private:

	UPROPERTY(EditAnywhere, Category = "Wave")
	float WaveDelay;

	FTimerHandle TimerWaveDelay;

	void WaveDelayed();

	
	
};
