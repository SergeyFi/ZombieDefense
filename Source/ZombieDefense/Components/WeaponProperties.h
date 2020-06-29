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

public:

	UPROPERTY(EditAnywhere)
	float Damage;

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

	UFUNCTION(BlueprintCallable)
	void UpdateFireComponentProperties();
	
		
};
