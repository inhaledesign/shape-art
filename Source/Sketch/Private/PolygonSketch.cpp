#include "PolygonSketch.h"


// We need a default constructor for tests. However, we do not want to
// allocate anything with no size. A poly with no size *should* throw
// exceptions.
PolygonSketch::PolygonSketch() {};

PolygonSketch::PolygonSketch(int VertexCount) {
    Size = VertexCount;
    Vertices.Init(FVector(0.0), VertexCount);
}

TArray<int32> PolygonSketch::GenerateTriangles() {
    TArray<int32> Triangles;

    for(int i = 0; i < Size; i++) {
        Triangles.Add(i);
    }
    return Triangles;
}

TArray<FVector> PolygonSketch::GenerateNormals() {
    TArray<FVector> Normals;
    Normals.Init(FVector(0, 0, 1), Size);	
    return Normals;
}

TArray<FVector2D> PolygonSketch::GenerateUV() {
    // TODO: This only works for a triangle
	TArray<FVector2D> UV;
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(1, 0));
	UV.Add(FVector2D(0, 1));
	return UV;
}