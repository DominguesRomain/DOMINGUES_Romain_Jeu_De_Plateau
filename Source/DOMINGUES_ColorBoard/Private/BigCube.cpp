// Fill out your copyright notice in the Description page of Project Settings.


#include "BigCube.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

ABigCube::ABigCube()
{
    PrimaryActorTick.bCanEverTick = true;

    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
    if (CubeAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeAsset.Object);
    }
}

void ABigCube::BeginPlay()
{
    Super::BeginPlay();
    ChangeColor();
}

void ABigCube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABigCube::ChangeColor()
{
    UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(CubeMesh->GetMaterial(0), this);
    FLinearColor NewColor = FLinearColor::MakeRandomColor();
    DynMaterial->SetVectorParameterValue(TEXT("Color"), NewColor);
    CubeMesh->SetMaterial(0, DynMaterial);
}
