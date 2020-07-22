// Copyright 2020 Sergey Firsov


#include "WeaponCritChanceUp.h"

#include "ZombieDefense/Components/Weapon/WeaponProperties.h"

void UWeaponCritChanceUp::UpgradeVirtual()
{
    auto WeaponPropComp =  GetOwner()->FindComponentByClass<UWeaponProperties>();

    if (WeaponPropComp)
    {
        float CritChanceNew = WeaponPropComp->GetCriticalDamageChance() + UpgradeStep;

        WeaponPropComp->SetCiriticalDamageChance(CritChanceNew);
    }
}
