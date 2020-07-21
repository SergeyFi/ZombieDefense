// Copyright 2020 Sergey Firsov


#include "DamageResistUpgrade.h"

#include "ZombieDefense/Components/HealthComponent.h"


void UDamageResistUpgrade::UpgradeVirtual()
{
	auto HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();

	if (HealthComponent)
	{
		HealthComponent->AddDamageResist(UpgradeStep);
	}
}
