// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentePlataforma.h"
#include "ComponenteArma.generated.h"

/**
 * 
 */
UCLASS()
class AVENTURAUSFX022026L1_API AComponenteArma : public AComponentePlataforma
{
	GENERATED_BODY()
public:
	AComponenteArma();
	virtual void ComportamientoIndividual(float Deltatime) override;
	
};
