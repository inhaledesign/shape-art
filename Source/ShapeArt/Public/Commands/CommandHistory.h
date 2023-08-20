#pragma once

#include "CoreMinimal.h"
#include "CanvasCommand.h"
#include "CommandHistory.generated.h"

UCLASS()
class SHAPEART_API UCommandHistory : public UObject {

    GENERATED_BODY()

    TArray<ICanvasCommand*> UndoStack { TArray<ICanvasCommand*>() };

    TArray<ICanvasCommand*> RedoStack { TArray<ICanvasCommand*>() };

    public:

    UCommandHistory() {};

    void Post(ICanvasCommand* Command);

    ICanvasCommand* Undo();

    ICanvasCommand* Redo();

    int UndoCount() { return UndoStack.Num(); }

    int RedoCount() { return RedoStack.Num(); }
};