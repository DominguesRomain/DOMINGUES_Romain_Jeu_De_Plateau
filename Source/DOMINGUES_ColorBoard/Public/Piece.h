#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ScoreManager.h"

#include "Piece.generated.h"

UCLASS()
class DOMINGUES_COLORBOARD_API APiece : public AActor
{
	GENERATED_BODY()

public:
	APiece();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin")
	int32 CoinValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin")
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed = 50.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	USphereComponent* CollisionSphere;

	void SetRandomPosition();

private:
	TArray<float> PossiblePositions = { -400.0f, -200.0f, 0.0f, 200.0f, 400.0f };

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);
};