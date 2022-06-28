// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/DamageType.h"
#include "ProjectileBaseC.generated.h"

class UProjectileMovementComponent;
class UCapsuleComponent;
class UParticleSystemComponent;
UCLASS()
class AProjectileBaseC : public AActor
{
	GENERATED_BODY()
	
private:

	
public:	
	// Sets default values for this actor's properties
	AProjectileBaseC();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")		
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")		
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")	
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")	
	UParticleSystemComponent* ParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditdefaultsOnly, Category = "Projectile")
	TSubclassOf<UDamageType> DamageTypeK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float MovementSpeed = 1000;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle DelayTimerHandle;

	UFUNCTION()
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void CheckKelime(AActor* HitActor);

	UFUNCTION(BlueprintImplementableEvent)
	void PlaySoundX();
};
