// Copyright 2020 Sergey Firsov


#include "WeaponCritDamageUp.h"
#include "ZombieDefense/Components/Weapon/WeaponProperties.h"

void UWeaponCritDamageUp::UpgradeVirtual()
{
    auto WeaponPropComp =  GetOwner()->FindComponentByClass<UWeaponProperties>();

    if (WeaponPropComp)
    {
        float CritDamageNew = WeaponPropComp->GetDamageMultiplier() + UpgradeStep;

        WeaponPropComp->SetDamageMultiplier(CritDamageNew);
    }
}
