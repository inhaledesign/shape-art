#include "SketchMeshGenerator.h"


void SketchMeshGenerator::AddToMesh(UProceduralMeshComponent* Mesh) {
	TArray<int32> Triangles = GenerateTriangles();
	TArray<FVector> Normals = GenerateNormals();
	TArray<FVector2D> UV = GenerateUV();
	TArray<FProcMeshTangent> Tangents = GenerateMeshTangents();
	TArray<FLinearColor> VertexColors = GenerateVertexColors();
	Mesh->CreateMeshSection_LinearColor(0, Polygon->GetVertices(), Triangles, Normals, UV, VertexColors, Tangents, false);
}

TArray<int32> SketchMeshGenerator::GenerateTriangles() {
    TArray<int32> Triangles;
	int Size { Polygon->GetSize() };

    for(int i = 0; i < Size; i++) {
        Triangles.Add(i);
    }
    return Triangles;
}

TArray<FVector> SketchMeshGenerator::GenerateNormals() {
    int Size { Polygon->GetSize() };
    TArray<FVector> Normals;
    Normals.Init(FVector(0, 0, 1), Size);	
    return Normals;
}

TArray<FVector2D> SketchMeshGenerator::GenerateUV() {
    // TODO: This only works for a triangle
	TArray<FVector2D> UV;
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(1, 0));
	UV.Add(FVector2D(0, 1));
	return UV;
}

TArray<FProcMeshTangent> SketchMeshGenerator::GenerateMeshTangents() {
	int Size { Polygon->GetSize() };
	FProcMeshTangent Tangent { FProcMeshTangent(0, 1, 0) }; // Tangents are all the same
	TArray<FProcMeshTangent> Tangents { TArray<FProcMeshTangent>() }; 
    Tangents.Init(Tangent, Size);
	return Tangents;
}

TArray<FLinearColor> SketchMeshGenerator::GenerateVertexColors() {
	int Size { Polygon->GetSize() };
	FLinearColor Color { FLinearColor(1.0, 0.0, 0.0, 0.5) }; // Making everything red for now.
	TArray<FLinearColor> VertexColors { TArray<FLinearColor>() };
	VertexColors.Init(Color, Size);
	return VertexColors;
}