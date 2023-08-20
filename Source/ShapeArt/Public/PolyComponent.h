#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralMeshComponent.h"
#include "PolyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHAPEART_API UPolyComponent : public USceneComponent {
	
	GENERATED_BODY()
																																
public:	
	UPolyComponent();

	void BeginPlay();

	void Copy(const UPolyComponent* FromPoly);
				
	UPROPERTY(EditAnywhere, Category = "ShapeArt")
    TArray<FVector> Vertices;

	void Destroy();

private:
    UProceduralMeshComponent* Mesh;

	void InitMesh();																																																																																																																																

	void BuildMesh();																

	void AddMaterialToMesh();

	void AttachMesh();

};