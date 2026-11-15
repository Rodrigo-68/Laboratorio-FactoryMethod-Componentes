#include "AventuraUSFX022026L1GameMode.h"
#include "AventuraUSFX022026L1Pawn.h"
#include "Plataforma.h"
#include "Engine/World.h"
#include "Inventory.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "FabricaAbstractaObstaculos.h"
#include "FabricaObstaculosAereos.h"
#include "FabricaObstaculosTerrestres.h"
#include "Obstaculo.h"
#include "ConstructorPlataformaBasica.h"
#include "ConstructorPlataformaAvanzada.h"
#include "DirectorPlataforma.h"
#include "Engine/Engine.h"
#include "FabricaComponentes.h"
#include "ComponentePlataforma.h"
#include "TipoComponente.h"

AAventuraUSFX022026L1GameMode::AAventuraUSFX022026L1GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAventuraUSFX022026L1Pawn::StaticClass();

	tipoPlataformaActual = 0;
}

void AAventuraUSFX022026L1GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World == nullptr)
	{
		return;
	}

	// ===== SINGLETON DEL INVENTARIO =====
	/*
	for (int i = 0; i <= 4; i++)
	{
		AInventory* SpawnedInventory = GetWorld()->SpawnActor<AInventory>(AInventory::StaticClass());
		if (SpawnedInventory)
		{
			Inventory = SpawnedInventory;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"), *Inventory->GetName()));
		}
	}
	*/

	// ===== ABSTRACT FACTORY PARA OBSTACULOS =====
	/*
	AFabricaAbstractaObstaculos* FabricaAerea = World->SpawnActor<AFabricaObstaculosAereos>(AFabricaObstaculosAereos::StaticClass());
	AFabricaAbstractaObstaculos* FabricaTerrestre = World->SpawnActor<AFabricaObstaculosTerrestres>(AFabricaObstaculosTerrestres::StaticClass());

	TArray<AFabricaAbstractaObstaculos*> FabricasAbstractas = { FabricaAerea, FabricaTerrestre };
	FRotator RotacionAF = FRotator::ZeroRotator;

	for (int32 f = 0; f < FabricasAbstractas.Num(); f++)
	{
		for (int32 i = 0; i < 100; i++)
		{
			FVector Base(FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(-1500.0f, 1500.0f), 200.0f);
			AObstaculo* NuevoObs = FabricasAbstractas[f]->CrearObstaculoEstatico(Base, RotacionAF);
			if (NuevoObs)
			{
				aPlataformas.Add(NuevoObs);
			}
		}
	}
	*/

	// ===== CREACIÓN DE LAS 200 PLATAFORMAS =====
	/*
	for (int32 i = 0; i < 200; i++)
	{
		FVector SpawnLocation(
			FMath::RandRange(-2000.0f, 2000.0f),
			FMath::RandRange(-2000.0f, 2000.0f),
			FMath::RandRange(100.0f, 1000.0f)
		);
		FRotator Rotacion = FRotator::ZeroRotator;
		APlataforma* NuevaPlataforma = World->SpawnActor<APlataforma>(SpawnLocation, Rotacion);
		if (NuevaPlataforma)
		{
			aPlataformas.Add(NuevaPlataforma);
		}
	}
	*/

	// ===== BUILDER DE PLATAFORMAS =====
	/*
	AConstructorPlataformaBasica* ConstructorBasico = World->SpawnActor<AConstructorPlataformaBasica>(AConstructorPlataformaBasica::StaticClass());
	AConstructorPlataformaAvanzada* ConstructorAvanzado = World->SpawnActor<AConstructorPlataformaAvanzada>(AConstructorPlataformaAvanzada::StaticClass());
	ADirectorPlataforma* Director = World->SpawnActor<ADirectorPlataforma>(ADirectorPlataforma::StaticClass());

	Director->SetConstructor(ConstructorBasico);
	Director->ConstruirPlataformaBasica(FVector(0, -500, 200), FRotator::ZeroRotator);
	APlataforma* PlataformaBasica = ConstructorBasico->ObtenerPlataforma();
	if (PlataformaBasica) aPlataformas.Add(PlataformaBasica);

	Director->SetConstructor(ConstructorAvanzado);
	Director->ConstruirPlataformaCompleta(FVector(0, 500, 200), FRotator::ZeroRotator);
	APlataforma* PlataformaAvanzada = ConstructorAvanzado->ObtenerPlataforma();
	if (PlataformaAvanzada) aPlataformas.Add(PlataformaAvanzada);
	*/


	// ===== FACTORY METHOD DE COMPONENTES =====

	// 1. Crear la fábrica
	AFabricaComponentes* FabricaComp = World->SpawnActor<AFabricaComponentes>(AFabricaComponentes::StaticClass());

	// 2. Lista de tipos para crear aleatoriamente
	TArray<ETipoComponente> TiposDisponibles = {
		ETipoComponente::ESCUDO,
		ETipoComponente::MOTOR,
		ETipoComponente::ARMA
	};

	// 3. Crear 15 componentes y guardarlos en el TMap
	for (int32 i = 0; i < 15; i++)
	{
		ETipoComponente TipoAleatorio = TiposDisponibles[FMath::RandRange(0, TiposDisponibles.Num() - 1)];
		FVector SpawnLoc(FMath::RandRange(-800.0f, 800.0f), FMath::RandRange(-800.0f, 800.0f), 200.0f);

		AComponentePlataforma* NuevoComp = FabricaComp->CrearComponente(TipoAleatorio, SpawnLoc, FRotator::ZeroRotator);

		if (NuevoComp)
		{
			// Asignamos el ID único y lo guardamos en el TMap
			NuevoComp->IDComponente = ContadorIDComponente;
			MapaComponentes.Add(ContadorIDComponente, NuevoComp);
			ContadorIDComponente++;
		}
	}

	// 4. Ejecutar el comportamiento de GRUPO para todos
	TArray<AComponentePlataforma*> TodosLosComponentes;
	MapaComponentes.GenerateValueArray(TodosLosComponentes);

	for (AComponentePlataforma* Comp : TodosLosComponentes)
	{
		if (Comp)
		{
			Comp->ComportamientoDeGrupo(TodosLosComponentes, GetWorld()->GetDeltaSeconds());
		}
	}

	// Timer de eliminación (comentado por si lo necesitas después)
	// GetWorldTimerManager().SetTimer(TimerEliminarPlataforma, this, &AAventuraUSFX022026L1GameMode::EliminarPlataforma, 0.3f, true);
}

void AAventuraUSFX022026L1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAventuraUSFX022026L1GameMode::EliminarPlataforma()
{
	if (aPlataformas.Num() > 0)
	{
		int32 IndiceAleatorio = FMath::RandRange(0, aPlataformas.Num() - 1);
		APlataforma* PlataformaAEliminar = aPlataformas[IndiceAleatorio];
		if (PlataformaAEliminar != nullptr)
		{
			PlataformaAEliminar->Destroy();
			aPlataformas.RemoveAt(IndiceAleatorio);
		}
	}
}