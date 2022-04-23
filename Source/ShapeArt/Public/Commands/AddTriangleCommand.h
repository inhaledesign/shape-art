#pragma once

#include "CoreMinimal.h"
#include "Commands/SketchCommand.h"
#include "SketchActor.h"
#include "AddTriangleCommand.generated.h"


UCLASS(BlueprintType)
class SHAPEART_API UAddTriangleCommand : public UObject, public ISketchCommand
{
	GENERATED_BODY()
	
	ASketchActor* TriangleActor { nullptr };

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Execute(UWorld* World);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Undo();
};