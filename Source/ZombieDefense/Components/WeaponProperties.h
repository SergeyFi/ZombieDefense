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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void BindToFireComponent();

	UFUNCTION()
	void UpdateProjectile(AActor* Projectile);

	UPROPERTY(EditAnywhere)
	float Damage;
	
protected:
	UPROPERTY(EditAnywhere)
    float FireRate;

	UPROPERTY(EditAnywhere)
    float CriticalDamageMultiplier;

	UPROPERTY(EditAnywhere)
    float CriticalDamageChance;

	UPROPERTY(EditAnywhere)
    float AmmoCurrent;

	UPROPERTY(EditAnywhere)
    float AmmoCapacity;
	
	UPROPERTY(EditAnywhere)
    float ReloadSpeed;

public:
	
	UFUNCTION(BlueprintCallable)
	void UpdateFireComponentProperties();

	float GetDamage() const;

	UFUNCTION(BlueprintCallable)
	void SetDamage(float DamageNew);
	
	float GetFireRate() const;

	UFUNCTION(BlueprintCallable)
	void SetFireRate(float FireRateNew);
	
	float GetCriticalDamageMultiplier() const;
	
	UFUNCTION(BlueprintCallable)
	void SetCriticalDamageMultiplier(float CriticalDamageMultiplierNew);
	
	float GetCriticalDamageChance() const;

	UFUNCTION(BlueprintCallable)
	void SetCriticalDamageChance(float CriticalDamageChanceNew);
	
	float GetAmmoCurrent() const;

	UFUNCTION(BlueprintCallable)
	void SetAmmoCurrent(float AmmoCurrentNew);
	
	float GetAmmoCapacity() const;
	
	UFUNCTION(BlueprintCallable)
	void SetAmmoCapacity(float AmmoCapacityNew);
	
	float GetReloadSpeed() const;

	UFUNCTION(BlueprintCallable)
	void SetReloadSpeed(float ReloadSpeedNew);
	
		
};
