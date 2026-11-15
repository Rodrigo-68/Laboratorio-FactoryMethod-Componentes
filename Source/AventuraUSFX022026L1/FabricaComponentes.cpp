// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaComponentes.h"
#include "ComponentePlataforma.h"
#include "ComponenteEscudo.h"
#include "ComponenteMotor.h"
#include "ComponenteArma.h"

AComponentePlataforma* AFabricaComponentes::CrearComponente(ETipoComponente Tipo, FVector Location, FRotator Rotation)
{
	AComponentePlataforma* NuevoComponente = nullptr;

	switch (Tipo)
	{
	case ETipoComponente::ESCUDO:
		NuevoComponente = GetWorld()->SpawnActor<AComponenteEscudo>(Location, Rotation);
		break;
	case ETipoComponente::MOTOR:
		NuevoComponente = GetWorld()->SpawnActor<AComponenteMotor>(Location, Rotation);
		break;
	case ETipoComponente::ARMA:
		NuevoComponente = GetWorld()->SpawnActor<AComponenteArma>(Location, Rotation);
		break;
	default:
		break;
	}

	return NuevoComponente;
}

