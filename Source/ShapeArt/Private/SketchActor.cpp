#include "SketchActor.h"
#include "PolygonSketch.h"
#include "Math/UnrealMathUtility.h"

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

void ASketchActor::AddTriangleMesh() {
	PolygonSketch Polygon { 3 };
	int RandX = FMath::RandRange(-150, 50);
	int RandY = FMath::RandRange(-150, 50);
	Polygon.SetVertex(0, RandX, RandY);
	Polygon.SetVertex(1, RandX, RandY + 100);
	Polygon.SetVertex(2, RandX + 100, RandY);
    TArray<int32> Triangles = Polygon.GenerateTriangles();
	TArray<FVector> Normals = Polygon.GenerateNormals();
	TArray<FVector2D> UV = Polygon.GenerateUV();
	TArray<FProcMeshTangent> Tangents; 
    Tangents.Init(FProcMeshTangent(0, 1, 0), Polygon.GetSize());
	TArray<FLinearColor> VertexColors;
	VertexColors.Add(FLinearColor(1.0, 0.0, 0.0, 0.5));
	VertexColors.Add(FLinearColor(0.0, 1.0, 0.0, 0.5));
	VertexColors.Add(FLinearColor(0.0, 0.0, 1.0, 0.5));
    Mesh->CreateMeshSection_LinearColor(0, Polygon.GetVertices(), Triangles, Normals, UV, VertexColors, Tangents, false);
}