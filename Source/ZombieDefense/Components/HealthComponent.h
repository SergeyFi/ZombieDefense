// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HealthCurrent;

	UPROPERTY(EditAnywhere)
	float HealthMax;

	UPROPERTY(EditAnywhere)
	float DamageResistance;

	UPROPERTY(EditAnywhere)
	bool DestroyOnHealthEnded;

public:	
	void AddHealth(float Heal);

	void RemoveHealth(float Damage);

	void AddDamageResist(float DamageResist);

	void RemoveDamageResist(float DamageResist);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthEvent, float, Health);

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthEnded;

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthDamaged;

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthHeal;
};
