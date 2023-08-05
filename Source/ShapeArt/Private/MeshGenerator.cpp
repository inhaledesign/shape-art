#include "MeshGenerator.h"

void MeshGenerator::AddToMesh(UProceduralMeshComponent* Mesh) {
	TArray<int32> Triangles = GenerateTriangles();
	TArray<FVector> Normals = GenerateNormals();
	TArray<FVector2D> UV = GenerateUV();
	TArray<FProcMeshTangent> Tangents = GenerateMeshTangents();
	TArray<FLinearColor> VertexColors = GenerateVertexColors();
	Mesh->CreateMeshSection_LinearColor(0, *Vertices, Triangles, Normals, UV, VertexColors, Tangents, false);
}

// Note: This is fast but does not work for non-convex polygons.
TArray<int32> MeshGenerator::GenerateTriangles() {
	int Size { Vertices->Num() };
    TArray<int32> TriangleIndices;

    TriangleIndices.Add(0);
    TriangleIndices.Add(1);
    TriangleIndices.Add(2);


    for (int32 i = 2; i < Size - 1; i++) {
        TriangleIndices.Add(0);
        TriangleIndices.Add(i);
        TriangleIndices.Add(i + 1);
    }

    return TriangleIndices;
}

TArray<FVector> MeshGenerator::GenerateNormals() {
    TArray<FVector> EmptyArray;
    return EmptyArray;
}

TArray<FVector2D> MeshGenerator::GenerateUV() {
	TArray<FVector2D> EmptyArray;
	return EmptyArray;
}

TArray<FProcMeshTangent> MeshGenerator::GenerateMeshTangents() {
	TArray<FProcMeshTangent> EmptyArray;
	return EmptyArray;
}

TArray<FLinearColor> MeshGenerator::GenerateVertexColors() {
	int Size { Vertices->Num() };
	FLinearColor Color { FLinearColor(1.0, 0.0, 0.0, 1.0) }; // Making everything red for now.
	TArray<FLinearColor> VertexColors { TArray<FLinearColor>() };
	VertexColors.Init(Color, Size);
	return VertexColors;
}