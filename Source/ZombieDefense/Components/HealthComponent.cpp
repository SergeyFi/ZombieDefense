// Copyright 2020 Sergey Firsov


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	HealthMax = 100.0f;
	HealthCurrent = HealthMax;

	HealthRegen = 1.0f;
	HealthRegenRate = 1.0f;

	bDestroyOnHealthEnded = true;
	
}

void UHealthComponent::StartHealthRegen()
{
	if (bHealthRegen)
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHealthRegen, this,
			&UHealthComponent::HealthRegeneration, HealthRegenRate, true);
	}
}

void UHealthComponent::HealthRegeneration()
{
	AddHealth(HealthRegen * HealthRegenRate);

	if (HealthCurrent >= HealthMax)
	{
		StopHealthRegen();
	}
}

void UHealthComponent::StopHealthRegen()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHealthRegen);
}

void UHealthComponent::AddHealth(float Heal, AActor* Instigator)
{
	HealthCurrent += Heal;

	OnHealthHeal.Broadcast(Instigator, Heal);
	OnHealthChanged.Broadcast(Instigator, HealthCurrent);

	if (HealthCurrent > HealthMax)
	{
		HealthCurrent = HealthMax;
		OnHealthHealed.Broadcast(Instigator, HealthCurrent);
	}
}

void UHealthComponent::RemoveHealth(float Damage, AActor* Instigator)
{
	HealthCurrent -= Damage * (1.0f - DamageResistance);

	OnHealthDamaged.Broadcast(Instigator, Damage);
	OnHealthChanged.Broadcast(Instigator, HealthCurrent);

	if (HealthCurrent <= 0.0f)
	{
		HealthCurrent = 0.0f;
		
		OnHealthEnded.Broadcast(Instigator, HealthCurrent);

		if (bDestroyOnHealthEnded)
		{
			GetOwner()->Destroy();
		}
	}

	StartHealthRegen();
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

void UHealthComponent::IncreaseMaxHealth(float HealthUpgrade)
{
	HealthMax += HealthUpgrade;
}

void UHealthComponent::IncreaseHealthRegen(float HealthRegenUpgrade)
{
	HealthRegen += HealthRegenUpgrade;
}
