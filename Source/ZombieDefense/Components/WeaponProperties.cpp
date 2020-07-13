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

float UWeaponProperties::GetDamage() const
{
	return Damage;
}

void UWeaponProperties::SetDamage(float DamageNew)
{
	ApplyWeaponProperties();
	this->Damage = DamageNew;
}

float UWeaponProperties::GetFireRate() const
{
	return FireRate;
}

void UWeaponProperties::SetFireRate(float FireRateNew)
{
	ApplyWeaponProperties();
	this->FireRate = FireRateNew;
}

float UWeaponProperties::GetCriticalDamageMultiplier() const
{
	return CriticalDamageMultiplier;
}

void UWeaponProperties::SetCriticalDamageMultiplier(float CriticalDamageMultiplierNew)
{
	ApplyWeaponProperties();
	this->CriticalDamageMultiplier = CriticalDamageMultiplierNew;
}

float UWeaponProperties::GetCriticalDamageChance() const
{
	return CriticalDamageChance;
}

void UWeaponProperties::SetCriticalDamageChance(float CriticalDamageChanceNew)
{
	ApplyWeaponProperties();
	this->CriticalDamageChance = CriticalDamageChanceNew;
}
