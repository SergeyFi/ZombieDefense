// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpgradeComponent.generated.h"


UCLASS( meta=(IsBlueprintBase="false") )
class ZOMBIEDEFENSE_API UUpgradeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUpgradeComponent();

	void Upgrade();

	void UpgradeUnlimit();

	void UpgradeAddLevel(int Level);

protected:
	
	virtual void UpgradeVirtual(float UpgradeStepNew);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int LevelCurrent;

private:

	UPROPERTY(EditAnywhere)
	int MineralsUpgradeStep;

	UPROPERTY(EditAnywhere)
    int MineralsToUpgrade;

	UPROPERTY(EditAnywhere)
	float UpgradeStep;

	UPROPERTY(VisibleAnywhere)
	float UpgradeStepTotal;

	UPROPERTY(EditAnywhere)
	float UpgradeLimit;
		
};
