#include "ComponenteArma.h"
#include "Components/StaticMeshComponent.h"

AComponenteArma::AComponenteArma()
{
	TipoComponente = ETipoComponente::ARMA;
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshArma"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (MeshAsset.Succeeded()) Mesh->SetStaticMesh(MeshAsset.Object);
	RootComponent = Mesh;
	SetActorScale3D(FVector(0.5f));
}

void AComponenteArma::ComportamientoIndividual(float DeltaTime)
{
	// Apuntar hacia arriba y abajo
	AddActorLocalRotation(FRotator(30.0f * DeltaTime, 0, 0));
}