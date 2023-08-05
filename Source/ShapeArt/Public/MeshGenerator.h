#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"

class MeshGenerator {

    TArray<FVector>* Vertices { nullptr };
    
    TArray<FVector> GenerateNormals();

    TArray<FVector2D> GenerateUV();

    TArray<int32> GenerateTriangles();

	TArray<FProcMeshTangent> GenerateMeshTangents();
	
	TArray<FLinearColor> GenerateVertexColors();

public:
    MeshGenerator(TArray<FVector>* Vertices) : Vertices(Vertices) {}

    void AddToMesh(UProceduralMeshComponent* Mesh);
};