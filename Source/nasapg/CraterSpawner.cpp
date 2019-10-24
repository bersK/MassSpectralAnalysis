// Fill out your copyright notice in the Description page of Project Settings.


#include "CraterSpawner.h"

ACraterSpawner::ACraterSpawner()
{
 	PrimaryActorTick.bCanEverTick = true;
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    RootComponent = RootSceneComponent;

	arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));

}

void ACraterSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (size_t i = 0; i < samples_to_spawn; i++)
	{
		FHitResult hit;
		float rotation = (float)i * ( 360.0f / (float)samples_to_spawn);
		FRotator ArrowRot = FRotator(0.0f, rotation, 0.f);
		arrow->SetWorldRotation(ArrowRot, true, &hit, ETeleportType::None);
		SpawnSample();
	}
	
	
}

void ACraterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACraterSpawner::RelocateToGround(ASample__CPP* Sample)
{
	FVector comp_location = Sample->GetActorLocation();
	FVector Start = comp_location + FVector(0.f, 0.f, ground_check_range.X);
	FVector End = comp_location + FVector(0.f, 0.f, ground_check_range.Y);

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(Sample);

	FHitResult hit;

	GetWorld()->LineTraceSingleByChannel(hit, Start, End, ECC_WorldStatic, CollisionParams);

	// 20 units offset on the Z axis to prevent meshes from getting stuck into the ground
	// and/or other objects
	FVector hit_location = hit.Location + FVector(0.f, 0.f, 20.f);
	Sample->SetActorLocation(hit_location);
}

void ACraterSpawner::SpawnSample()
{
	FRotator rand_rot = FRotator(0.f, FMath::RandRange(0, 360), 0.f);
	float f_rad_range = FMath::RandRange(ACraterSpawner::radius_range.X, ACraterSpawner::radius_range.Y);
	FVector loc = arrow->GetComponentLocation() + arrow->GetForwardVector() * f_rad_range;
	FActorSpawnParameters SpawnProps;

	ASample__CPP* Sample = GetWorld()->SpawnActor<ASample__CPP>( loc, rand_rot, SpawnProps ) ;
	UE_LOG(LogTemp, Warning, TEXT("%s"),*loc.ToString());
	if(Sample)
	{
		// RelocateToGround(Sample);
		AdjustNewMass(Sample);
	}

}

void ACraterSpawner::AdjustNewMass(ASample__CPP* Sample)
{
	if (Sample)
	Sample->SM_Sample->SetMassOverrideInKg( FName(""), FMath::RandRange(mass_sample_kg.X, mass_sample_kg.Y), true);
}

