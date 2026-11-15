#include "ComponenteMotor.h"
#include "Components/StaticMeshComponent.h"

AComponenteMotor::AComponenteMotor()
{
	TipoComponente = ETipoComponente::MOTOR;
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshMotor"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset.Succeeded()) Mesh->SetStaticMesh(MeshAsset.Object);
	RootComponent = Mesh;
	SetActorScale3D(FVector(0.5f, 0.5f, 0.2f));
}

void AComponenteMotor::ComportamientoIndividual(float DeltaTime)
{
	// Vibración simulada (movimiento local en Z)
	FVector NuevaLoc = GetActorLocation();
	NuevaLoc.Z += FMath::Sin(GetWorld()->GetTimeSeconds() * 10.0f) * 2.0f;
	SetActorLocation(NuevaLoc);
}