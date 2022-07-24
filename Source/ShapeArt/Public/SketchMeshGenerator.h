#pragma once

#include "PolygonSketch.h"
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"

class SketchMeshGenerator {

    PolygonSketch* Polygon { nullptr };
    
    TArray<FVector> GenerateNormals();

    TArray<FVector2D> GenerateUV();

    TArray<int32> GenerateTriangles();

	TArray<FProcMeshTangent> GenerateMeshTangents();
	
	TArray<FLinearColor> GenerateVertexColors();

public:
    SketchMeshGenerator(PolygonSketch* Polygon) : Polygon(Polygon) {}

    void AddToMesh(UProceduralMeshComponent* Mesh);

};