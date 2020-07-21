// Copyright 2020 Sergey Firsov


#include "HealthRegenUpgrade.h"

#include "ZombieDefense/Components/HealthComponent.h"

void UHealthRegenUpgrade::UpgradeVirtual()
{
    auto HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();

    if (HealthComponent)
    {
        HealthComponent->IncreaseHealthRegen(UpgradeStep);
    }
}
