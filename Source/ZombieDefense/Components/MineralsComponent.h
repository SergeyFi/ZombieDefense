// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MineralsComponent.generated.h"


UCLASS( meta=(IsBlueprintBase="true") )
class ZOMBIEDEFENSE_API UMineralsComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UMineralsComponent();

	UFUNCTION(BlueprintCallable)
	void AddMinerals(int Amount);

	UFUNCTION(BlueprintCallable)
	void RemoveMinerals(int Amount);

	UFUNCTION(BlueprintCallable)
	int GetMinerals();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMineralsDelegate, float, Amount);

	UPROPERTY(BlueprintAssignable)
	FMineralsDelegate OnAddMinerals;
	
protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void AddMineralsToKiller(AActor* Instigator, float Health);

	void BindToOwnerHealth();

	UPROPERTY(EditAnywhere)
	int Minerals;

	UPROPERTY(EditAnywhere)
	bool bAddMineralsToKiller;
	
};
