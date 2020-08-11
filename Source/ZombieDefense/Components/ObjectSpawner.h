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

	UFUNCTION(BlueprintCallable)
	void StartSpawn();

	UFUNCTION(BlueprintCallable)
	void StopSpawn();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void SpawnObject();

	UFUNCTION()
	virtual void OnSpawnedObjDestroy(AActor* DestroyedActor);
	
	UPROPERTY(EditAnywhere)
	int SpawnCount;

	UPROPERTY(VisibleAnywhere)
	int SpawnCurrent;

	UPROPERTY(VisibleAnywhere)
	int SpawnTotal;


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
