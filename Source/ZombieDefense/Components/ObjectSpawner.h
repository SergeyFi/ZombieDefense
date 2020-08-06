// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectSpawner.generated.h"

UENUM(BlueprintType)
enum class ESpawnerType : uint8
{
	Circle UMETA(DisplayName = "Circle")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UObjectSpawner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectSpawner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void SpawnObject();

	void StartSpawn();

	void StopSpawn();
	
	virtual void OnSpawnedObjDestroy(AActor* DestroyedActor);
	
	UPROPERTY(EditAnywhere)
	int SpawnCountInitial;

	UPROPERTY(EditAnywhere)
	int SpawnCountIncrease;

	UPROPERTY(VisibleAnywhere)
	int SpawnCurrent;


private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnClass;

	UPROPERTY(EditAnywhere)
	bool bStartOnBeginPlay;

	UPROPERTY(EditAnywhere)
	float SpawnRate;

	UPROPERTY(EditAnywhere)
	int MaxSpawnAttempts;
	
	UPROPERTY(EditAnywhere)
	ESpawnerType SpawnerType;

	UPROPERTY(EditAnywhere)
	float OutRadius;

	UPROPERTY(EditAnywhere)
	float InnerRadius;

	FVector GeneratePointInCircle(float OutRad, float InRad);

	FRotator RandomRotation();

	FTimerHandle SpawnTimer;
		
};
