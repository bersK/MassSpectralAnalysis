// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Sample__CPP.h"
#include "Components/ArrowComponent.h"
#include "CraterSpawner.generated.h"

UCLASS()
class NASAPG_API ACraterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACraterSpawner();

public:

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* RootSceneComponent;

public: 

	UPROPERTY(VisibleAnywhere)
	UArrowComponent* arrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D radius_range = FVector2D(150.0f, 200.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ground_check_range = FVector2D(100.0f, 400.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D mass_sample_kg = FVector2D(90.0f, 300.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int samples_to_spawn = 70;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector sample_scale = FVector(0.25f);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void SpawnSample();

	UFUNCTION()
	void RelocateToGround(ASample__CPP* Sample);

	UFUNCTION()
	void AdjustNewMass(ASample__CPP* Sample);
};
