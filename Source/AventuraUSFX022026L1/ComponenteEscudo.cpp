#include "ComponenteEscudo.h"
#include "Components/StaticMeshComponent.h"

AComponenteEscudo::AComponenteEscudo()
{
	TipoComponente = ETipoComponente::ESCUDO;
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEscudo"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded()) Mesh->SetStaticMesh(MeshAsset.Object);
	RootComponent = Mesh;
	SetActorScale3D(FVector(1.5f));
}

void AComponenteEscudo::ComportamientoIndividual(float DeltaTime)
{
	// Rotación individual
	AddActorLocalRotation(FRotator(0, 50.0f * DeltaTime, 0));
}

void AComponenteEscudo::ComportamientoDeGrupo(TArray<AComponentePlataforma*> GrupoComponentes, float DeltaTime)
{
	// Si hay más de 2 escudos, se hacen más grandes (comportamiento de grupo)
	if (GrupoComponentes.Num() > 2)
	{
		SetActorScale3D(FVector(2.0f));
	}
}