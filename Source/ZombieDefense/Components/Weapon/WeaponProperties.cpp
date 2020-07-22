// Copyright 2020 Sergey Firsov


#include "WeaponProperties.h"

#include "FireComponent.h"
#include "ZombieDefense/Components/Weapon/DamagerComponent.h"

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
	ApplyWeaponProperties();
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

void UWeaponProperties::UpdateFireComponent()
{
	TArray<UFireComponent*> FireComponents;
	GetOwner()->GetComponents<UFireComponent>(FireComponents);

	for (auto FireComponent : FireComponents)
	{
		if (FireComponent)
		{
			FireComponent->FireRate = FireRate;
			FireComponent->IsAutomatic = bIsAutomatick;
		}
	}
}

void UWeaponProperties::ApplyWeaponProperties()
{
	UpdateFireComponent();
}

float UWeaponProperties::GetDamage()
{
	return  Damage;
}

void UWeaponProperties::SetDamage(float DamageNew)
{
	Damage = DamageNew;
}

float UWeaponProperties::GetFireRate()
{
	return FireRate;
}

void UWeaponProperties::SetFireRate(float FireRateNew)
{
	FireRate = FireRateNew;

	ApplyWeaponProperties();
}

float UWeaponProperties::GetDamageMultiplier()
{
	return CriticalDamageMultiplier;
}

void UWeaponProperties::SetDamageMultiplier(float CriticalDamageMyltiNew)
{
	CriticalDamageMultiplier = CriticalDamageMyltiNew;
}

float UWeaponProperties::GetCriticalDamageChance()
{
	return CriticalDamageChance;
}

void UWeaponProperties::SetCiriticalDamageChance(float CriticalDamageChanceNew)
{
	CriticalDamageChance = CriticalDamageChanceNew;
}
