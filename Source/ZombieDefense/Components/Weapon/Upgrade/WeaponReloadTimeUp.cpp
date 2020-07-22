// Copyright 2020 Sergey Firsov


#include "WeaponReloadTimeUp.h"

#include "ZombieDefense/Components/Weapon/AmmoComponent.h"

void UWeaponReloadTimeUp::UpgradeVirtual()
{
    auto AmmoComponent = GetOwner()->FindComponentByClass<UAmmoComponent>();

    if (AmmoComponent)
    {
        float ReloadTimeNew = AmmoComponent->GetReloadTime() + UpgradeStep;

        AmmoComponent->SetReloadTime(ReloadTimeNew);
    }
}
