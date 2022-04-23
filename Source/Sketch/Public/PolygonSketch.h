#pragma once
#include "CoreMinimal.h"
#include "Sketch.h"

class SKETCH_API PolygonSketch : public Sketch {
    int Size;
    TArray<FVector> Vertices;

public:
    PolygonSketch();

    PolygonSketch(int VertexCount);

    int GetSize() { return Size; }
    
    FVector GetVertex(int Index) { return Vertices.GetData()[Index]; }
    
    void SetVertex(int Index, double X, double Y) {
        FVector& Vertex = Vertices[Index];
        Vertex.X = X;
        Vertex.Y = Y;
        // Z should always be 0, and so does not need changing.
    }
    
    TArray<FVector> GetVertices() { return Vertices; }
    
    TArray<int32> GenerateTriangles();
	
    TArray<FVector> GenerateNormals();
	
    TArray<FVector2D> GenerateUV();
};