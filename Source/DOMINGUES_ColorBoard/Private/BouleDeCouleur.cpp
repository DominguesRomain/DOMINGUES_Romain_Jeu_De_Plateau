#include "BouleDeCouleur.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// Constructeur
ABouleDeCouleur::ABouleDeCouleur()
{
	// Créer un composant Static Mesh
	BouleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BouleMesh"));
	RootComponent = BouleMesh;

	// Charger un mesh par défaut (par exemple une sphère)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereMesh.Succeeded())
	{
		BouleMesh->SetStaticMesh(SphereMesh.Object);
	}
}

// Appelée au démarrage
void ABouleDeCouleur::BeginPlay()
{
	Super::BeginPlay();

	// Créer un matériau dynamique pour la boule
	if (BouleMesh)
	{
		UMaterialInterface* BaseMaterial = BouleMesh->GetMaterial(0);
		if (BaseMaterial)
		{
			DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
			BouleMesh->SetMaterial(0, DynamicMaterial);
		}
	}
}

// Fonction pour changer la couleur
void ABouleDeCouleur::SetColor(FLinearColor NewColor)
{
	if (DynamicMaterial)
	{
		DynamicMaterial->SetVectorParameterValue(TEXT("BaseColor"), NewColor);
	}
}