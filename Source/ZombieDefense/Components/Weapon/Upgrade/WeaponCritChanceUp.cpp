// Copyright 2020 Sergey Firsov


#include "WeaponCritChanceUp.h"

#include "ZombieDefense/Components/Weapon/WeaponProperties.h"

void UWeaponCritChanceUp::UpgradeVirtual(float UpgradeStepNew)
{
    auto WeaponPropComp =  GetOwner()->FindComponentByClass<UWeaponProperties>();

    if (WeaponPropComp)
    {
        float CritChanceNew = WeaponPropComp->GetCriticalDamageChance() + UpgradeStepNew;

        WeaponPropComp->SetCiriticalDamageChance(CritChanceNew);
    }
}
