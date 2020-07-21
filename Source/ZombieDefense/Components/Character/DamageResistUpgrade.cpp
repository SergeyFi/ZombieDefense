// Copyright 2020 Sergey Firsov


#include "DamageResistUpgrade.h"

#include "ZombieDefense/Components/HealthComponent.h"

// Sets default values for this component's properties
UDamageResistUpgrade::UDamageResistUpgrade()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UDamageResistUpgrade::UpgradeVirtual()
{
	auto HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();

	if (HealthComponent)
	{
		HealthComponent->AddDamageResist(UpgradeValue);
	}
}
