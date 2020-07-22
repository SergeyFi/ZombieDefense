// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class ZOMBIEDEFENSE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
