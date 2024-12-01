#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bolide.generated.h"

UCLASS()
class DOMINGUES_COLORBOARD_API ABolide : public APawn
{
	GENERATED_BODY()

public:
	ABolide();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void MoveRight();

	void MoveLeft();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float CurrentPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxPosition = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinPosition = -400.0f;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};