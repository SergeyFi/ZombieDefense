// Copyright 2020 Sergey Firsov


#include "WeaponProperties.h"

#include "FireComponent.h"
#include "ZombieDefense/Components/DamagerComponent.h"

// Sets default values for this component's properties
UWeaponProperties::UWeaponProperties()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UWeaponProperties::BeginPlay()
{
	Super::BeginPlay();

	BindToFireComponent();
	UpdateFireComponentProperties();
}

void UWeaponProperties::BindToFireComponent()
{
	TArray<UFireComponent*> FireComponents;
	GetOwner()->GetComponents<UFireComponent>(FireComponents);

	for (auto FireComponent : FireComponents)
	{
		if (FireComponent)
		{
			FireComponent->OnProjectileSpawned.AddDynamic(this, &UWeaponProperties::UpdateProjectile);
		}
	}
}

void UWeaponProperties::UpdateProjectile(AActor* Projectile)
{
	if (Projectile)
	{
		auto Damager = Projectile->FindComponentByClass<UDamagerComponent>();

		if (Damager)
		{
			Damager->Damage = Damage;
			Damager->CriticalDamageMultiplier = CriticalDamageMultiplier;
			Damager->CriticalDamageChance = CriticalDamageChance;
		}
	}
}

void UWeaponProperties::UpdateFireComponentProperties()
{
	TArray<UFireComponent*> FireComponents;
	GetOwner()->GetComponents<UFireComponent>(FireComponents);

	for (auto FireComponent : FireComponents)
	{
		if (FireComponent)
		{
			FireComponent->FireRate = FireRate;
		}
	}
}

