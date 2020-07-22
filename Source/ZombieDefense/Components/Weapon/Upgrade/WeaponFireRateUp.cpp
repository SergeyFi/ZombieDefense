// Copyright 2020 Sergey Firsov


#include "WeaponFireRateUp.h"

#include "ZombieDefense/Components/Weapon/WeaponProperties.h"

void UWeaponFireRateUp::UpgradeVirtual()
{
    auto WeaponPropComp =  GetOwner()->FindComponentByClass<UWeaponProperties>();

    if (WeaponPropComp)
    {
        float FireRateNew = WeaponPropComp->GetFireRate() + UpgradeStep;

        WeaponPropComp->SetFireRate(FireRateNew);
    }
}
