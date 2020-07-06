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

float UWeaponProperties::GetDamage() const
{
	return Damage;
}

void UWeaponProperties::SetDamage(float DamageNew)
{
	UpdateFireComponentProperties();
	this->Damage = DamageNew;
}

float UWeaponProperties::GetFireRate() const
{
	return FireRate;
}

void UWeaponProperties::SetFireRate(float FireRateNew)
{
	UpdateFireComponentProperties();
	this->FireRate = FireRateNew;
}

float UWeaponProperties::GetCriticalDamageMultiplier() const
{
	return CriticalDamageMultiplier;
}

void UWeaponProperties::SetCriticalDamageMultiplier(float CriticalDamageMultiplierNew)
{
	UpdateFireComponentProperties();
	this->CriticalDamageMultiplier = CriticalDamageMultiplierNew;
}

float UWeaponProperties::GetCriticalDamageChance() const
{
	return CriticalDamageChance;
}

void UWeaponProperties::SetCriticalDamageChance(float CriticalDamageChanceNew)
{
	UpdateFireComponentProperties();
	this->CriticalDamageChance = CriticalDamageChanceNew;
}

float UWeaponProperties::GetAmmoCurrent() const
{
	return AmmoCurrent;
}

void UWeaponProperties::SetAmmoCurrent(float AmmoCurrentNew)
{
	UpdateFireComponentProperties();
	this->AmmoCurrent = AmmoCurrentNew;
}

float UWeaponProperties::GetAmmoCapacity() const
{
	return AmmoCapacity;
}

void UWeaponProperties::SetAmmoCapacity(float AmmoCapacityNew)
{
	UpdateFireComponentProperties();
	this->AmmoCapacity = AmmoCapacityNew;
}

float UWeaponProperties::GetReloadSpeed() const
{
	return ReloadSpeed;
}

void UWeaponProperties::SetReloadSpeed(float ReloadSpeedNew)
{
	UpdateFireComponentProperties();
	this->ReloadSpeed = ReloadSpeedNew;
}

