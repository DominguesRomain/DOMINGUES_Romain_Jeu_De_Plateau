#include "Piece.h"
#include "Math/UnrealMathUtility.h"
#include "ScoreManager.h" 

APiece::APiece()
{
    PrimaryActorTick.bCanEverTick = true;

    CoinValue = 10;
    CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
    RootComponent = CoinMesh;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    CollisionSphere->SetupAttachment(RootComponent);
    CollisionSphere->InitSphereRadius(50.0f);

    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APiece::OnOverlapBegin);

    SetRandomPosition();
}

void APiece::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor)
    {
        AScoreManager* ScoreManager = Cast<AScoreManager>(UGameplayStatics::GetGameMode(this));
        if (ScoreManager)
        {
            ScoreManager->AddScore(CoinValue);
        }

        Destroy();
    }
}

void APiece::BeginPlay()
{
    Super::BeginPlay();
}

void APiece::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    NewLocation.Z -= Speed * DeltaTime;
    SetActorLocation(NewLocation);

    if (NewLocation.Z < -1000.0f)
    {
        Destroy();
    }
}

void APiece::SetRandomPosition()
{
    int32 RandomIndex = FMath::RandRange(0, PossiblePositions.Num() - 1);
    float RandomPosition = PossiblePositions[RandomIndex];

    SetActorLocation(FVector(RandomPosition, 0.0f, 0.0f));
}