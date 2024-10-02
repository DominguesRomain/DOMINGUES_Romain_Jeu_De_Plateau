// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonDai.generated.h"

UCLASS()
class DOMINGUES_COLORBOARD_API AMonDai : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonDai();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FFloatRange entier;
	FInt8Range result;
	FInt8Range NbDice;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void RandomNumber();
	UFUNCTION(BlueprintCallable)
	void ResetNbDIce();
};
