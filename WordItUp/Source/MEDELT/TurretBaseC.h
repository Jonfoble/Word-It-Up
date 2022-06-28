// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "TurretBaseC.generated.h"


class AProjectileBaseC;
UCLASS()
class MEDELT_API ATurretBaseC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurretBaseC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ChildMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurretFeatures")
	TSubclassOf<AProjectileBaseC> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurretFeatures")
	TEnumAsByte<ECollisionChannel> CollisionChannel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = "true"))
	class UAimComponent* MyAimComponent;


	FTimerHandle FireRateTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TurretFeatures", meta= (AllowPrivateAccess = "true"))
	float FireRate=3.0f;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Fire();
	
	float AimPitch;

	float AimYaw;
	
	void BindToInput();
};
