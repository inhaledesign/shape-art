#pragma once

#include "CoreMinimal.h"
#include "PolygonSketch.h"
#include "SketchData.generated.h"


// ListView will only use data object that are classes. Structs do not work. /shrug

UCLASS(Blueprintable)
class SHAPEART_API USketchData : public UObject {

	GENERATED_BODY()

public:

    USketchData() {}

	PolygonSketch Polygon { PolygonSketch(3) };
};