#include "Bolide.h"

ABolide::ABolide()
{
	PrimaryActorTick.bCanEverTick = true;

	CurrentPosition = 0.0f;

}

void ABolide::BeginPlay()
{
	Super::BeginPlay();
}

void ABolide::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABolide::MoveRight()
{
	CurrentPosition += 200.0f;

	if (CurrentPosition > MaxPosition)
	{
		CurrentPosition = MaxPosition;
	}

	SetActorLocation(FVector(CurrentPosition, 0.0f, 0.0f));
}

void ABolide::MoveLeft()
{
	CurrentPosition -= 200.0f;

	if (CurrentPosition < MinPosition)
	{
		CurrentPosition = MinPosition;
	}

	SetActorLocation(FVector(CurrentPosition, 0.0f, 0.0f));
}

void ABolide::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ABolide::MoveRight);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ABolide::MoveLeft);
}