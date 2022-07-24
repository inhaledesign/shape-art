#include "SketchActor.h"
#include "PolygonSketch.h"
#include "Math/UnrealMathUtility.h"
#include "SketchMeshGenerator.h"

ASketchActor::ASketchActor() {
	PrimaryActorTick.bCanEverTick = false;
	InitMesh();
	AddMaterialToMesh();
}

void ASketchActor::InitMesh() {
	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Generated Mesh"));
	if(Mesh == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Could not create Mesh object"));
		throw "Could not create Mesh object";
	}
	SetRootComponent(Mesh);
}

void ASketchActor::AddMaterialToMesh() {
	auto MaterialPath { TEXT("Material'/Game/Materials/VertexColor.VertexColor'") };
	UMaterialInterface* Material = LoadObject<UMaterialInterface>(NULL, MaterialPath, NULL, LOAD_None, NULL);

	if(Material == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Material did not load: \"%s\""), MaterialPath);
		throw "Material did not load";
	}

	Mesh->SetMaterial(0, Material);
}

void ASketchActor::SetSketch(PolygonSketch& PolygonSketch) {
	Polygon = &PolygonSketch;
	SketchMeshGenerator Generator { SketchMeshGenerator(Polygon) };
	Generator.AddToMesh(Mesh);
}
