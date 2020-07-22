// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponProperties.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEDEFENSE_API UWeaponProperties : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponProperties();

	UFUNCTION(BlueprintCallable)
	void ApplyWeaponProperties();

	float GetDamage();

	void SetDamage(float DamageNew);

	float GetFireRate();

	void SetFireRate(float FireRateNew);

	float GetDamageMultiplier();

	void SetDamageMultiplier(float CriticalDamageMyltiNew);

	float GetCriticalDamageChance();

	void SetCiriticalDamageChance(float CriticalDamageChanceNew);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void BindToFireComponent();

	UFUNCTION()
	void UpdateProjectile(AActor* Projectile);

	UPROPERTY(EditAnywhere)
	float Damage;
	
	UPROPERTY(EditAnywhere)
    float FireRate;

	UPROPERTY(EditAnywhere)
	bool bIsAutomatick;

	UPROPERTY(EditAnywhere)
    float CriticalDamageMultiplier;

	UPROPERTY(EditAnywhere)
    float CriticalDamageChance;

	void UpdateFireComponent();
		
};
