// Copyright 2020 Sergey Firsov


#include "WeaponDamageUp.h"

#include "ZombieDefense/Components/Weapon/WeaponProperties.h"

void UWeaponDamageUp::UpgradeVirtual()
{
    auto WeaponPropComp =  GetOwner()->FindComponentByClass<UWeaponProperties>();

    if (WeaponPropComp)
    {
        float NewDamage = WeaponPropComp->GetDamage() + UpgradeStep;

        WeaponPropComp->SetDamage(NewDamage);
    }
}
