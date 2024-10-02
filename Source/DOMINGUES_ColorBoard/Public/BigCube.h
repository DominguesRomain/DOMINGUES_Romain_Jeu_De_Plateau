// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BigCube.generated.h"

UCLASS(Blueprintable)
class DOMINGUES_COLORBOARD_API ABigCube : public AActor
{
    GENERATED_BODY()

public:
    ABigCube();
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor FinalColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInstance* Mater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* CubeMesh;

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    UFUNCTION(BlueprintCallable)
    void ChangeColor();

private:

};