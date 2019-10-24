// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MetadataComponent_CPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NASAPG_API UMetadataComponent_CPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMetadataComponent_CPP();


	UPROPERTY(BlueprintReadWrite)
	float iron_oxide;
	
	UPROPERTY(BlueprintReadWrite)
	float silica;

	UPROPERTY(BlueprintReadWrite)
	float alumina;

	UPROPERTY(BlueprintReadWrite)
	float magnesia;

	UPROPERTY(BlueprintReadWrite)
	float lime;

	UPROPERTY(BlueprintReadWrite)
	float sodium_oxide;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
