// Copyright 2020 Sergey Firsov


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	HealthCurrent = HealthMax;
	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UHealthComponent::AddHealth(float Heal)
{
	HealthCurrent += Heal;

	HealthHeal.Broadcast(Heal);
	HealthChanged.Broadcast(HealthCurrent);

	if (HealthCurrent > HealthMax)
	{
		HealthCurrent = HealthMax;
	}
}

void UHealthComponent::RemoveHealth(float Damage)
{
	HealthCurrent -= Damage * (1.0f - DamageResistance);

	HealthDamage.Broadcast(Damage);
	HealthChanged.Broadcast(HealthCurrent);

	if (HealthCurrent < 0.0f)
	{
		HealthCurrent = 0.0f;
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

