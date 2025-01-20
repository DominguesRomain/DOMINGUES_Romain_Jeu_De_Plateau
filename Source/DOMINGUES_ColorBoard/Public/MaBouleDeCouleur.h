// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaBouleDeCouleur.generated.h"

UCLASS()
class DOMINGUES_COLORBOARD_API AMaBouleDeCouleur : public AActor
{
	GENERATED_BODY()

public:
	AMaBouleDeCouleur();

protected:
	virtual void BeginPlay() override;

public:
	TArray<FString> AvailableColors;
	TArray<FString> GeneratedColors;
	
	void GenerateColors();
};
