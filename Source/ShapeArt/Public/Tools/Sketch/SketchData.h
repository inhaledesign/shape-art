#pragma once

#include "CoreMinimal.h"
#include "PolygonSketch.h"
#include "SketchData.generated.h"


UCLASS(Blueprintable)
class SHAPEART_API USketchData : public UObject {

	GENERATED_BODY()

public:

    USketchData() {
		Polygon.SetVertex(0, 0, 0);
		Polygon.SetVertex(1, 0, 100);
		Polygon.SetVertex(2, 100, 0);
	}

	PolygonSketch Polygon { PolygonSketch(3) };
};