// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "ZombieDefense/Components/Character/UpgradeComponent.h"
#include "MovementSpeedUpgrade.generated.h"


UCLASS( meta=(IsBlueprintBase="true") )
class ZOMBIEDEFENSE_API UMovementSpeedUpgrade : public UUpgradeComponent
{
	GENERATED_BODY()

private:
	
	virtual void UpgradeVirtual(float UpgradeStepNew) override;
};
