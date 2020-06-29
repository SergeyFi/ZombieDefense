// Copyright 2020 Sergey Firsov


#include "FireComponent.h"
#include "ZombieDefense/Weapons/Projectile.h"

// Sets default values for this component's properties
UFireComponent::UFireComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}


// Called when the game starts
void UFireComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UFireComponent::Fire()
{
	if (ProjectileClass)
	{
		FActorSpawnParameters SpawnParams;
		
		

		AActor* Projectile
		= GetWorld()->SpawnActor<AProjectile>(ProjectileClass, GetComponentTransform(), SpawnParams);

		OnProjectileSpawned.Broadcast(Projectile);
	}
}

void UFireComponent::FireStart()
{
	GetWorld()->GetTimerManager().SetTimer(FireTimer, this, &UFireComponent::Fire, FireRate, IsAutomatic);
}

void UFireComponent::FireStop()
{
	GetWorld()->GetTimerManager().ClearTimer(FireTimer);
}

