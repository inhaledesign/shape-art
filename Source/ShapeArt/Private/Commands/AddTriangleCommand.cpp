#include "Commands/AddTriangleCommand.h"
#include "SketchLibrary.h"
    
void UAddTriangleCommand::Execute_Implementation(UWorld* world) {
    TriangleActor = USketchLibrary::AddTriangleToWorld(world);
}

void UAddTriangleCommand::Undo_Implementation() {
    if(TriangleActor != nullptr) {
        TriangleActor->Destroy();
        TriangleActor = nullptr;
    }
}