#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ScoreManager.generated.h"

UCLASS()
class DOMINGUES_COLORBOARD_API AScoreManager : public AGameModeBase
{
    GENERATED_BODY()

public:
    AScoreManager();

    void AddScore(int32 ScoreToAdd);

    void StartTimer();

protected:
    virtual void BeginPlay() override;

private:

    int32 CurrentScore;

    FTimerHandle GameTimerHandle;

    const float TimerDuration = 40.0f;

    void EndGame();

    // Méthode pour mettre à jour l'affichage du score, mais j'ai pas de widget pour l'instant
    void UpdateScoreDisplay();
};