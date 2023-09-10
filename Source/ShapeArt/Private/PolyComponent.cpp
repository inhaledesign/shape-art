#include "PolyComponent.h"
#include "ProceduralMeshComponent.h"
#include "MeshGenerator.h"


UPolyComponent::UPolyComponent() {
	PrimaryComponentTick.bCanEverTick = false;
	bAllowAnyoneToDestroyMe = true;
	InitMesh();
	AddMaterialToMesh();
}

void UPolyComponent::BeginPlay() {
	BuildMesh();
	AttachMesh();
	USceneComponent::BeginPlay();
}

void UPolyComponent::Copy(const UPolyComponent* FromPoly) {
	Vertices = FromPoly->Vertices; 
}

void UPolyComponent::InitMesh() {
    Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
	if(Mesh == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Could not create Mesh object"));
	}
}

void UPolyComponent::AddMaterialToMesh() {
	auto MaterialPath { TEXT("Material'/Game/Materials/VertexColor.VertexColor'") };
	UMaterialInterface* Material = LoadObject<UMaterialInterface>(NULL, MaterialPath, NULL, LOAD_None, NULL);

	if(Material == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Material did not load: \"%s\""), MaterialPath);
	}

	Mesh->SetMaterial(0, Material);
}

void UPolyComponent::BuildMesh() {
    if (Vertices.Num() < 3) { return; }

	auto Generator { MeshGenerator(&Vertices) };
	Generator.AddToMesh(Mesh);
}

void UPolyComponent::AttachMesh() {	Mesh->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform); }

void UPolyComponent::Destroy() {
	Mesh->DestroyComponent();
	Mesh = nullptr;
	DestroyComponent();
}