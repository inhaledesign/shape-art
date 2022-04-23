#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SketchCommand.generated.h"


UINTERFACE(MinimalAPI)
class USketchCommand : public UInterface
{
	GENERATED_BODY()
};


class SHAPEART_API ISketchCommand
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Execute(UWorld* World);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Undo();
};
