// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "ZombieDefense/Components/Character/UpgradeComponent.h"
#include "WeaponCritDamageUp.generated.h"


UCLASS()
class ZOMBIEDEFENSE_API UWeaponCritDamageUp : public UUpgradeComponent
{
	GENERATED_BODY()

private:

	virtual void UpgradeVirtual() override;
	
};