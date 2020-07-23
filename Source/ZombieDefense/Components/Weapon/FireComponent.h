// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FireComponent.generated.h"


UCLASS( meta=(IsBlueprintBase="true") )
class ZOMBIEDEFENSE_API UFireComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFireComponent();

	UFUNCTION(BlueprintCallable)
	void FireStart();

	UFUNCTION(BlueprintCallable)
    void FireStop();

	UPROPERTY(EditAnywhere)
	float FireRate;

	UPROPERTY(EditAnywhere)
	bool IsAutomatic;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool CanFire;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProjectileSpawned, AActor*, Projectile);

	UPROPERTY(BlueprintAssignable)
	FProjectileSpawned OnProjectileSpawned;

	UFUNCTION(BlueprintCallable)
    void BlockFire();

	UFUNCTION(BlueprintCallable)
    void UnblockFire();

protected:

	UPROPERTY(EditAnywhere)
    TSubclassOf<class AProjectile> ProjectileClass;

	void Fire();

	FTimerHandle FireTimer;
	
};
