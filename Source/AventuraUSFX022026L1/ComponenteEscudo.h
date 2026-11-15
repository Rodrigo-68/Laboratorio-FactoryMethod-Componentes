// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentePlataforma.h"
#include "GameFramework/Actor.h"
#include "ComponenteEscudo.generated.h"

UCLASS()
class AVENTURAUSFX022026L1_API AComponenteEscudo : public AComponentePlataforma
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponenteEscudo();
	virtual void ComportamientoIndividual(float DeltaTime) override;
	virtual void ComportamientoDeGrupo(TArray<AComponentePlataforma*> GrupoComponentes, float DeltaTime) override;
};
