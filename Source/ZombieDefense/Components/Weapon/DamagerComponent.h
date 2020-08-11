// Copyright 2020 Sergey Firsov

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DamagerComponent.generated.h"


UCLASS( meta=(IsBlueprintBase="true") )
class ZOMBIEDEFENSE_API UDamagerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamagerComponent();

	UPROPERTY(EditAnywhere)
	float Damage;

	UPROPERTY(EditAnywhere)
	float CriticalDamageChance;

	UPROPERTY(EditAnywhere)
	float CriticalDamageMultiplier;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCriticalDamageEvent, float, CriticalDamage);

	UPROPERTY(BlueprintAssignable)
	FCriticalDamageEvent OnCriticalDamage;

protected:

	void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UShapeComponent* DetectorShape;

	UFUNCTION()
	void OnDetectorOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void DestroyProjectile();


};
