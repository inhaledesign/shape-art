#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SketchActor.h"
#include "SketchLibrary.generated.h"

UCLASS()
class SHAPEART_API USketchLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static ASketchActor* AddSketchActorToWorld(UWorld* World, FVector const& Location, FRotator const& Rotation);

public:
	UFUNCTION(BlueprintCallable, category = "Sketch",  meta = (WorldContext="WorldContext"))
	static ASketchActor* AddTriangleToWorld(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, category = "Sketch",  meta = (WorldContext="WorldContext"))
	static void RemoveAllSketchesFromWorld(UObject* WorldContext);
};