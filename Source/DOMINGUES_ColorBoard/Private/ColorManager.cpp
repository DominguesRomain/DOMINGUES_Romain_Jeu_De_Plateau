#include "ColorManager.h"
#include "Math/UnrealMathUtility.h"
#include "BouleDeCouleur.h"

// Constructeur
AColorManager::AColorManager()
{
	PrimaryActorTick.bCanEverTick = false;

	// Initialisation des couleurs disponibles
	AvailableColors = {
		FLinearColor::Red,
		FLinearColor::Green,
		FLinearColor::Blue,
		FLinearColor::Yellow
	};
}

// Appelée au démarrage
void AColorManager::BeginPlay()
{
	Super::BeginPlay();

	// Vérification que des boules sont assignées
	if (Boules.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Aucune boule assignée au ColorManager !"));
		return;
	}

	// Générer des couleurs aléatoires
	TArray<FLinearColor> GeneratedColors = GenerateColors(Boules.Num());

	// Appliquer les couleurs aux boules
	for (int i = 0; i < Boules.Num(); i++)
	{
		if (Boules[i])
		{
			ABouleDeCouleur* Boule = Cast<ABouleDeCouleur>(Boules[i]);
			if (Boule)
			{
				Boule->SetColor(GeneratedColors[i]);
			}
		}
	}
}

// Génération de couleurs aléatoires
TArray<FLinearColor> AColorManager::GenerateColors(int NumColors)
{
	TArray<FLinearColor> GeneratedColors;

	for (int i = 0; i < NumColors; i++)
	{
		int RandomIndex = FMath::RandRange(0, AvailableColors.Num() - 1);
		GeneratedColors.Add(AvailableColors[RandomIndex]);
	}

	return GeneratedColors;
}