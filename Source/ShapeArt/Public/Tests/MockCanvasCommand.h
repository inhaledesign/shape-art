#pragma once

#include "CoreMinimal.h"
#include "Commands/CanvasCommand.h"
#include "MockCanvasCommand.generated.h"


UCLASS()
class SHAPEART_API UMockCanvasCommand : public UObject, public ICanvasCommand {

    GENERATED_BODY()

    public:

    UMockCanvasCommand() {};

    virtual void Execute(APolyGroupActor* Canvas) override {};

	virtual void Undo(APolyGroupActor* Canvas) override {};

};