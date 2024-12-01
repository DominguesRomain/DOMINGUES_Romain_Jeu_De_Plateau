#include "ScoreManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AScoreManager::AScoreManager()
{
    CurrentScore = 0;
}
void AScoreManager::BeginPlay()
{
    Super::BeginPlay();

    StartTimer();
}

void AScoreManager::AddScore(int32 ScoreToAdd)
{
    CurrentScore += ScoreToAdd;
    UpdateScoreDisplay();
}

void AScoreManager::StartTimer()
{
    GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &AScoreManager::EndGame, TimerDuration, false);
}

void AScoreManager::EndGame()
{
    UE_LOG(LogTemp, Warning, TEXT("FiniLooser"));

    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void AScoreManager::UpdateScoreDisplay()
{
    // Lier le score a un widget mais la c'est juste en train de casser mon unreal
}