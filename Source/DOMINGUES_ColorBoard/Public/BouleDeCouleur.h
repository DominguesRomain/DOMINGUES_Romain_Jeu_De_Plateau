#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BouleDeCouleur.generated.h"

UCLASS()
class DOMINGUES_COLORBOARD_API ABouleDeCouleur : public AActor
{
	GENERATED_BODY()

public:
	// Constructeur
	ABouleDeCouleur();

protected:
	// Appelée au démarrage
	virtual void BeginPlay() override;

public:
	// Fonction pour définir la couleur de la boule
	void SetColor(FLinearColor NewColor);

private:
	// Composant représentant la boule
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BouleMesh;

	// Matériau dynamique pour changer la couleur
	UMaterialInstanceDynamic* DynamicMaterial;
};