// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( meta=(IsBlueprintBase="true") )
class ZOMBIEDEFENSE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	void AddHealth(float Heal, AActor* Instigator = nullptr);

	void RemoveHealth(float Damage, AActor* Instigator = nullptr);

	void AddDamageResist(float DamageResist);

	void RemoveDamageResist(float DamageResist);

	void IncreaseMaxHealth(float HealthUpgrade);

	void IncreaseHealthRegen(float HealthRegenUpgrade);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthEvent, AActor*, Instigator, float, Health);

	UPROPERTY(BlueprintAssignable)
    FHealthEvent OnHealthEnded;

	UPROPERTY(BlueprintAssignable)
    FHealthEvent OnHealthDamaged;

	UPROPERTY(BlueprintAssignable)
    FHealthEvent OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
    FHealthEvent OnHealthHeal;

	UPROPERTY(BlueprintAssignable)
    FHealthEvent OnHealthHealed;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HealthCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HealthMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DamageResistance;

	UPROPERTY(EditAnywhere)
	bool bDestroyOnHealthEnded;

	UPROPERTY(EditAnywhere)
	bool bHealthRegen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HealthRegen;

	UPROPERTY(EditAnywhere)
	float HealthRegenRate;
	
	void StartHealthRegen();

	void HealthRegeneration();

	void StopHealthRegen();

	FTimerHandle TimerHealthRegen;

};
