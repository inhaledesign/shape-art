

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralMeshComponent.h"
#include "PolyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHAPEART_API UPolyComponent : public USceneComponent
{
	GENERATED_BODY()

public:	

	UPolyComponent();

	void BeginPlay();

	UFUNCTION(BlueprintCallable, Category = "ShapeArt")
	void SetVertices(const TArray<FVector>& Vertices);

protected:
	UPROPERTY(EditAnywhere, BlueprintSetter="SetVertices", Category = "ShapeArt")
    TArray<FVector> Vertices;

private:
    UProceduralMeshComponent* Mesh;

	void InitMesh();

	void BuildMesh();

	void AddMaterialToMesh();

	void AttachMesh();

};