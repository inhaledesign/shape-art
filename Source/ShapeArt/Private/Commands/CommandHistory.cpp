#include "Commands/CommandHistory.h"

void UCommandHistory::Post(ICanvasCommand *Command) {
    UndoStack.Push(Command);
    RedoStack.Empty();
}

ICanvasCommand* UCommandHistory::Undo() {
    const bool Shrink { true };

    if(UndoStack.Num() > 0){
        ICanvasCommand* Command { UndoStack.Pop(Shrink) };
        RedoStack.Push(Command);
        return Command;
    }

    return nullptr;
}

ICanvasCommand* UCommandHistory::Redo() {
    const bool Shrink { true };

    if(RedoStack.Num() > 0) {
        ICanvasCommand* Command { RedoStack.Pop(Shrink) };
        UndoStack.Push(Command);
        return Command;
    }

    return nullptr;
}
