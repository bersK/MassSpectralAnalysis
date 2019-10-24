// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Sample__CPP.generated.h"

UCLASS()
class NASAPG_API ASample__CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASample__CPP();


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sample")
	UActorComponent* MetaComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,  Category = "Sample")
	UStaticMeshComponent* SM_Sample;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sample")
	TArray<FString> sm_refs;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetStaticMeshFromArray();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
