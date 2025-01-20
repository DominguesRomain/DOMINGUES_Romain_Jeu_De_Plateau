#include "MaBouleDeCouleur.h"
#include "Math/UnrealMathUtility.h" // Pour FMath::RandRange
#include "Containers/Array.h"       // Pour TArray

// Constructeur
AMaBouleDeCouleur::AMaBouleDeCouleur()
{
	PrimaryActorTick.bCanEverTick = false;
	AvailableColors = { TEXT("Rouge"), TEXT("Vert"), TEXT("Bleu"), TEXT("Jaune") };
}

void AMaBouleDeCouleur::BeginPlay()
{
	Super::BeginPlay();
	GenerateColors();
}

void AMaBouleDeCouleur::GenerateColors()
{
	GeneratedColors.Empty();
	int Emplacement = 0;
	
	while (Emplacement < 4)
	{
		int RandomIndex = FMath::RandRange(0, AvailableColors.Num() - 1);
		FString RandomColor = AvailableColors[RandomIndex];
		
		GeneratedColors.Add(RandomColor);
		Emplacement++;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Couleurs générées :"));
	for (const FString& Color : GeneratedColors)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Color);
	}
}
