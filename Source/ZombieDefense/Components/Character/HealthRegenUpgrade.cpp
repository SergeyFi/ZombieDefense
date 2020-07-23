// Copyright 2020 Sergey Firsov


#include "HealthRegenUpgrade.h"

#include "ZombieDefense/Components/HealthComponent.h"

void UHealthRegenUpgrade::UpgradeVirtual(float UpgradeStepNew)
{
    auto HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();

    if (HealthComponent)
    {
        HealthComponent->IncreaseHealthRegen(UpgradeStepNew);
    }
}
