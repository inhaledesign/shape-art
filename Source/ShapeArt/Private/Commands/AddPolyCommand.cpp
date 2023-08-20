#include "Commands/AddPolyCommand.h"

void UAddPolyCommand::Execute(APolyGroupActor* Canvas) {
    Poly = Canvas->AddPolyByVertices(Vertices, Location);
}

void UAddPolyCommand::Undo(APolyGroupActor* Canvas) {
    Poly->Destroy();
    Poly = nullptr;
}