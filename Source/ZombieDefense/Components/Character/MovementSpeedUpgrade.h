// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "ZombieDefense/Components/Character/UpgradeComponent.h"
#include "MovementSpeedUpgrade.generated.h"


UCLASS()
class ZOMBIEDEFENSE_API UMovementSpeedUpgrade : public UUpgradeComponent
{
	GENERATED_BODY()

	virtual void UpgradeVirtual() override;
};
