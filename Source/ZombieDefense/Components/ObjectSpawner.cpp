// Copyright 2020 Sergey Firsov


#include "ObjectSpawner.h"

// Sets default values for this component's properties
UObjectSpawner::UObjectSpawner()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	MaxSpawnAttempts = 10;
	SpawnRate = 1.0f;
}

// Called when the game starts
void UObjectSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (bStartOnBeginPlay)
	{
		StartSpawn();
	}
}

void UObjectSpawner::SpawnObject()
{
	if (SpawnClass && SpawnerType == ESpawnerType::Circle)
	{
		AActor* SpawnedObject = nullptr;
		
		for (auto i = 0; i < MaxSpawnAttempts && !SpawnedObject; ++i)
		{
			auto SpawnLocation = GeneratePointInCircle(OutRadius, InnerRadius);

			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;

			SpawnedObject = GetWorld()->SpawnActor<AActor>(SpawnClass, SpawnLocation, RandomRotation(), SpawnParams);
		}

		if (SpawnedObject)
		{
			++SpawnCurrent;
			++SpawnTotal;
			
			SpawnedObject->OnDestroyed.AddDynamic(this, &UObjectSpawner::OnSpawnedObjDestroy);

			if (SpawnTotal >= SpawnCount)
			{
				StopSpawn();
				SpawnTotal = 0;
			}
		}
	}
}

void UObjectSpawner::StartSpawn()
{
	GetWorld()->GetTimerManager().SetTimer(SpawnTimer, this, &UObjectSpawner::SpawnObject, SpawnRate, true);
}

void UObjectSpawner::StopSpawn()
{
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimer);
}

FVector UObjectSpawner::GeneratePointInCircle(float OutRad, float InRad)
{
	if (InRad > OutRad)
	{
		auto temp = OutRad;
		OutRad = InRad;
		InRad = temp;
	}

	auto A = FMath::Sqrt(FMath::RandRange(0.0f, 1.0f)) * OutRad;
	A += InRad;
	
	auto B = FMath::RandRange(0.0f, 1.0f) * 2.0f * PI;

	auto B_Cos = FMath::Cos(B);
	auto B_Sin = FMath::Sin(B);

	return FVector(B_Cos * A, B_Sin * A, 0.0f);
}

FRotator UObjectSpawner::RandomRotation()
{
	return FRotator(0.0f, 0.0f, FMath::RandRange(0.0f, 360.0f));
}

void UObjectSpawner::OnSpawnedObjDestroy(AActor* DestroyedActor)
{
	--SpawnCurrent;
}
