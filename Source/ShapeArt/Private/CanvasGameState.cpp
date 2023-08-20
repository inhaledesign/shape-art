#include "CanvasGameState.h"


void ACanvasGameState::RunCommand(ICanvasCommand* Command, APolyGroupActor* Canvas) {
    Command->Execute(Canvas);
    History->Post(Command);
    HistoryChangedEvent.Broadcast();
}

void ACanvasGameState::Undo(APolyGroupActor* Canvas) {
    ICanvasCommand* Command { History->Undo() };

    if(Command) { 
        Command->Undo(Canvas); 
        HistoryChangedEvent.Broadcast();
    }
}

void ACanvasGameState::Redo(APolyGroupActor* Canvas) {
    ICanvasCommand* Command { History->Redo() };

    if(Command) { 
        Command->Execute(Canvas); 
        HistoryChangedEvent.Broadcast();    
    }
}