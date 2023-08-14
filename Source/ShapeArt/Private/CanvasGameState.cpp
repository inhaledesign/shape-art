#include "CanvasGameState.h"


void ACanvasGameState::RunCommand(const TScriptInterface<ICanvasCommand>&Command) {
    UWorld* World { GetWorld() };
    UObject* CommandObject { Command.GetObject() };
    ICanvasCommand::Execute_Execute(CommandObject, World);
    History.Post(CommandObject);
}

void ACanvasGameState::Undo() {
    UWorld* World { GetWorld() };
    UObject* CommandObject { History.GetCurrent()->GetValue() };
    ICanvasCommand::Execute_Undo(CommandObject);
    History.StepPrevious();
}

void ACanvasGameState::Redo() {
    UWorld* World { GetWorld() };
    History.StepNext();
    UObject* CommandObject { History.GetCurrent()->GetValue() };
    ICanvasCommand::Execute_Execute(CommandObject, World);
}