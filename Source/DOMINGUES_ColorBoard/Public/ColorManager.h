#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BouleDeCouleur.h"
#include "ColorManager.generated.h"

UCLASS()
class YOURPROJECT_API AColorManager : public AActor
{
	GENERATED_BODY()

public:
	// Constructeur
	AColorManager();

protected:
	virtual void BeginPlay() override;

public:
	// Liste des couleurs disponibles
	TArray<FLinearColor> AvailableColors;

	// Fonction pour générer des couleurs
	TArray<FLinearColor> GenerateColors(int NumColors);

	// Liste des boules à colorier
	UPROPERTY(EditAnywhere)
	TArray<AActor*> Boules;
};