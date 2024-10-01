// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BigCube.generated.h"

UCLASS()
class DOMINGUES_COLORBOARD_API ABigCube : public AActor
{
    GENERATED_BODY()

public:
    ABigCube();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void ChangeColor();

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* CubeMesh;
};