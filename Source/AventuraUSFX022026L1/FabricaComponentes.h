// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentePlataforma.h"
#include "FabricaComponentes.generated.h"

class AComponentePlataforma;

UCLASS()
class AVENTURAUSFX022026L1_API AFabricaComponentes : public AActor
{
	GENERATED_BODY()
	
public:
	AComponentePlataforma* CrearComponente(ETipoComponente Tipo, FVector Location, FRotator Rotation);
      

};
