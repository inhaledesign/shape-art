#include "SketchActor.h"
#include "PolygonSketch.h"
#include "Math/UnrealMathUtility.h"

ASketchActor::ASketchActor() {
	PrimaryActorTick.bCanEverTick = false;
	InitMesh();
	AddMaterialToMesh();
}

void ASketchActor::SetSketch(PolygonSketch& PolygonSketch) {
	Polygon = &PolygonSketch;
	GenerateMeshFromPolygon();
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

void ASketchActor::GenerateMeshFromPolygon() {
	TArray<int32> Triangles = Polygon->GenerateTriangles();
	TArray<FVector> Normals = Polygon->GenerateNormals();
	TArray<FVector2D> UV = Polygon->GenerateUV();
	TArray<FProcMeshTangent> Tangents = GenerateMeshTangents();
	TArray<FLinearColor> VertexColors = GenerateVertexColors();
	Mesh->CreateMeshSection_LinearColor(0, Polygon->GetVertices(), Triangles, Normals, UV, VertexColors, Tangents, false);
}

TArray<FProcMeshTangent> ASketchActor::GenerateMeshTangents() {
	int Size { Polygon->GetSize() };
	FProcMeshTangent Tangent { FProcMeshTangent(0, 1, 0) }; // Tangents are all the same
	TArray<FProcMeshTangent> Tangents { TArray<FProcMeshTangent>() }; 
    Tangents.Init(Tangent, Size);
	return Tangents;
}

TArray<FLinearColor> ASketchActor::GenerateVertexColors() {
	int Size { Polygon->GetSize() };
	FLinearColor Color { FLinearColor(1.0, 0.0, 0.0, 0.5) }; // Making everything red for now.
	TArray<FLinearColor> VertexColors { TArray<FLinearColor>() };
	VertexColors.Init(Color, Size);
	return VertexColors;
}