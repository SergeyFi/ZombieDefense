// Copyright 2020 Sergey Firsov


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

