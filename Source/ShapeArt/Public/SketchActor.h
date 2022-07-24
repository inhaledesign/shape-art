#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "PolygonSketch.h"
#include "SketchActor.generated.h"

UCLASS()
class SHAPEART_API ASketchActor : public AActor
{
	GENERATED_BODY()

	UProceduralMeshComponent* Mesh { nullptr };
	PolygonSketch* Polygon { nullptr };
	
	void InitMesh();
	
	void AddMaterialToMesh();
	
	void GenerateMeshFromPolygon();
	
	TArray<FProcMeshTangent> GenerateMeshTangents();
	
	TArray<FLinearColor> GenerateVertexColors();

public:	

	ASketchActor();

	void SetSketch(PolygonSketch& PolygonSketch);

};
