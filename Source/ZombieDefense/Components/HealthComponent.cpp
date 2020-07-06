// Copyright 2020 Sergey Firsov


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	HealthMax = 100.0f;
	HealthCurrent = HealthMax;
	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UHealthComponent::AddHealth(float Heal)
{
	HealthCurrent += Heal;

	OnHealthHeal.Broadcast(Heal);
	OnHealthChanged.Broadcast(HealthCurrent);

	if (HealthCurrent > HealthMax)
	{
		HealthCurrent = HealthMax;
	}
}

void UHealthComponent::RemoveHealth(float Damage)
{
	HealthCurrent -= Damage * (1.0f - DamageResistance);

	OnHealthDamaged.Broadcast(Damage);
	OnHealthChanged.Broadcast(HealthCurrent);

	if (HealthCurrent < 0.0f)
	{
		HealthCurrent = 0.0f;
	}

	if (HealthCurrent <= 0.0f)
	{
		OnHealthEnded.Broadcast(HealthCurrent);
	}
}

void UHealthComponent::AddDamageResist(float DamageResist)
{
	DamageResistance += DamageResist;

	if (DamageResistance > 1.0f)
	{
		DamageResistance = 1.0f;
	}
}

void UHealthComponent::RemoveDamageResist(float DamageResist)
{
	DamageResistance -= DamageResist;

	if (DamageResistance < 0.0f)
	{
		DamageResistance = 0.0f;
	}
}

