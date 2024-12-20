// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomCube.generated.h"

UCLASS(Blueprintable)
class DOMINGUES_COLORBOARD_API ACustomCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomCube();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor FinalColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* Mater;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CubeMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
