#pragma once

#include "CoreMinimal.h"
#include "Tools/Sketch/SketchData.h"
#include "SketchProvider.generated.h"

USTRUCT(BlueprintType)
struct SHAPEART_API FSketchProvider
{
	GENERATED_BODY()

	FSketchProvider() {}

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UObject*> Data { TArray<UObject*>() };
	
};