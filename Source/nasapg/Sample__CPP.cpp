
#include "Sample__CPP.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"

ASample__CPP::ASample__CPP()
{
 	PrimaryActorTick.bCanEverTick = true;

	sm_refs.Add(TEXT("StaticMesh'/Game/ThirdPersonBP/Nasa_Space_Apps_2019/Assets/Rock_01.Rock_01'"));
	sm_refs.Add(TEXT("StaticMesh'/Game/ThirdPersonBP/Nasa_Space_Apps_2019/Assets/Rock_02.Rock_02'"));
	sm_refs.Add(TEXT("StaticMesh'/Game/ThirdPersonBP/Nasa_Space_Apps_2019/Assets/Rock_03.Rock_03'"));
	sm_refs.Add(TEXT("StaticMesh'/Game/ThirdPersonBP/Nasa_Space_Apps_2019/Assets/Rock_04.Rock_04'"));

	MetaComponent = CreateDefaultSubobject<UActorComponent>(TEXT("MetaComp"));
	SM_Sample = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sample"));
	RootComponent = SM_Sample;

	int rand_end_range = sm_refs.Num()-1;

	FRandomStream Stream(FDateTime::Now().GetTicks());
	int rand_num = Stream.RandRange(0, rand_end_range);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(*sm_refs[rand_num]);
	UStaticMesh* Asset = MeshAsset.Object;

    SM_Sample->SetStaticMesh(Asset);

}

void ASample__CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASample__CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASample__CPP::SetStaticMeshFromArray()
{
}

