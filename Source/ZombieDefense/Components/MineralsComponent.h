// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "ZombieDefense/Components/AmountComponent.h"
#include "MineralsComponent.generated.h"


UCLASS()
class ZOMBIEDEFENSE_API UMineralsComponent : public UAmountComponent
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void AddMineralsToKiller(AActor* Instigator, float Health);

	void BindToOwnerHealth();

	UPROPERTY(EditAnywhere)
	bool bAddMineralsToKiller;
	
};
