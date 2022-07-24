#include "Commands/AddTriangleCommand.h"
#include "SketchLibrary.h"

void UAddTriangleCommand::Execute_Implementation(UWorld* World) {
    if(World != nullptr) {
        const FActorSpawnParameters SpawnParams { };
        TriangleActor = (ASketchActor*) World->SpawnActor(ASketchActor::StaticClass(), &Location, &Rotation, SpawnParams);
        TriangleActor->SetSketch(Polygon);
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Cannot add Sketch. Pointer to World was null."));
        throw "Failed to add Sketch.";
    }
}

void UAddTriangleCommand::Undo_Implementation() {
    if(TriangleActor != nullptr) {
        TriangleActor->Destroy();
        TriangleActor = nullptr;
    }
}