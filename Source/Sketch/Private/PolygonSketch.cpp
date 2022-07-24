#include "PolygonSketch.h"


// We need a default constructor for tests. However, we do not want to
// allocate anything with no size. A poly with no size *should* throw
// exceptions.
PolygonSketch::PolygonSketch() {};

PolygonSketch::PolygonSketch(int VertexCount) {
    Size = VertexCount;
    Vertices.Init(FVector(0.0), VertexCount);
}



TArray<FVector> PolygonSketch::GenerateNormals() {
    TArray<FVector> Normals;
    Normals.Init(FVector(0, 0, 1), Size);	
    return Normals;
}