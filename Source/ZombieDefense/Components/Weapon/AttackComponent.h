// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"


UCLASS( meta=(IsBlueprintBase="true") )
class ZOMBIEDEFENSE_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();

	UFUNCTION(BlueprintCallable)
	void AttackTarget(AActor* Target);

protected:

	UPROPERTY(EditAnywhere)
	float Damage;

	UPROPERTY(EditAnywhere)
    float DamageRate;

	bool CoolDown;

	FTimerHandle AttackTimer;

	void StartCoolDown();
	
	void StopCoolDown();
		
};
