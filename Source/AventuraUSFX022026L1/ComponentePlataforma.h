// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TipoComponente.h"
#include "ComponentePlataforma.generated.h"

UCLASS()
class AVENTURAUSFX022026L1_API AComponentePlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponentePlataforma();
	// ID único para el TMap
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componente")
	int32 IDComponente;

	// Propiedad tipo enumeración
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Componente")
	ETipoComponente TipoComponente;

	// Comportamiento individual
	virtual void ComportamientoIndividual(float DeltaTime);
	// Comportamiento de grupo (recibe a los demás componentes)
	virtual void ComportamientoDeGrupo(TArray<AComponentePlataforma*> GrupoComponentes, float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


};
