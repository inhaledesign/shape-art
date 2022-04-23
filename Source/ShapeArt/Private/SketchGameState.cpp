#include "SketchGameState.h"


void ASketchGameState::RunCommand(const TScriptInterface<ISketchCommand>&Command) {
    UWorld* World { GetWorld() };
    UObject* CommandObject { Command.GetObject() };
    ISketchCommand::Execute_Execute(CommandObject, World);
    History.Post(CommandObject);
}

void ASketchGameState::Undo() {
    UWorld* World { GetWorld() };
    UObject* CommandObject { History.GetCurrent()->GetValue() };
    ISketchCommand::Execute_Undo(CommandObject);
    History.StepPrevious();
}

void ASketchGameState::Redo() {
    UWorld* World { GetWorld() };
    History.StepNext();
    UObject* CommandObject { History.GetCurrent()->GetValue() };
    ISketchCommand::Execute_Execute(CommandObject, World);
}