#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CanvasCommand.generated.h"


UINTERFACE(MinimalAPI)
class UCanvasCommand : public UInterface {
	GENERATED_BODY()
};


class SHAPEART_API ICanvasCommand {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Execute(UWorld* World);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Undo();
};
