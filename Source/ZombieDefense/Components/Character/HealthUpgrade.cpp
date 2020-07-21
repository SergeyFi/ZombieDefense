// Copyright 2020 Sergey Firsov


#include "HealthUpgrade.h"


#include "ZombieDefense/Components/HealthComponent.h"

void UHealthUpgrade::UpgradeVirtual()
{
	auto HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();

	if (HealthComponent)
	{
		HealthComponent->IncreaseMaxHealth(UpgradeStep);
	}
}
