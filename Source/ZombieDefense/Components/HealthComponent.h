// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UHealthComponent : public USceneComponent
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

public:	
	void AddHealth(float Heal);

	void RemoveHealth(float Damage);

	void AddDamageResist(float DamageResist);

	void RemoveDamageResist(float DamageResist);

	DECLARE_EVENT_OneParam(UHealthComponent,FHealthStatus, float)

	FHealthStatus HealthDamage;
	FHealthStatus HealthHeal;
	FHealthStatus HealthChanged;
};
