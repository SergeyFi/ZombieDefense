// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "UpgradeComponent.h"
#include "DamageResistUpgrade.generated.h"


UCLASS( meta=(IsBlueprintBase="true") )
class ZOMBIEDEFENSE_API UDamageResistUpgrade : public UUpgradeComponent
{
	GENERATED_BODY()

private:

	virtual void UpgradeVirtual(float UpgradeStepNew) override;
		
};
