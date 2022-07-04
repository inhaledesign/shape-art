#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "SketchActor.generated.h"

UCLASS()
class SHAPEART_API ASketchActor : public AActor
{
	GENERATED_BODY()

	UProceduralMeshComponent* Mesh;
	void InitMesh();
	void AddMaterialToMesh();

public:	
	ASketchActor();

	void AddTriangleMesh();
};
