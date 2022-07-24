#pragma once

#include "CoreMinimal.h"
#include "Commands/SketchCommand.h"
#include "SketchActor.h"
#include "AddTriangleCommand.generated.h"


UCLASS(BlueprintType)
class SHAPEART_API UAddTriangleCommand : public UObject, public ISketchCommand {

	GENERATED_BODY()
	
	PolygonSketch Polygon { PolygonSketch(3) };
	ASketchActor* TriangleActor { nullptr };
	FVector Location { FVector() };
	FRotator Rotation { FRotator() };
	

public:

	UAddTriangleCommand() {
		Polygon.SetVertex(0, 0, 0);
		Polygon.SetVertex(1, 0, 100);
		Polygon.SetVertex(2, 100, 0);
	}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Execute(UWorld* World);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Undo();

	UFUNCTION(BlueprintCallable)
	void SetLocation(double X, double Y) {
		Location[0] = X;
		Location[1] = Y;
	}
	
};