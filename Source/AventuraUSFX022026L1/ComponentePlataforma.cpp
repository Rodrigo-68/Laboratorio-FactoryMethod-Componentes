// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentePlataforma.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AComponentePlataforma::AComponentePlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IDComponente = -1; // Se asignará al crearse
	TipoComponente = ETipoComponente::NUCLEO;

}

// Called when the game starts or when spawned
void AComponentePlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComponentePlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ComportamientoIndividual(DeltaTime);

}

void AComponentePlataforma::ComportamientoIndividual(float DeltaTime)
{
	// Comportamiento base (puedes dejar esto vacío o poner algo genérico)
}

void AComponentePlataforma::ComportamientoDeGrupo(TArray<AComponentePlataforma*> GrupoComponentes, float DeltaTime)
{
	// Comportamiento base de grupo
}

