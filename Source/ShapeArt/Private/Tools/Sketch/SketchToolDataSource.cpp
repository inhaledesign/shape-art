#include "Tools/Sketch/SketchToolDataSource.h"
#include "SketchActor.h"

void USketchToolDataSource::BindData(USketchData* SketchData, TSharedPtr<SActorWidget> ActorWidget, ASketchActor* SketchActor) {
    SketchActor->SetSketch(SketchData->Polygon);
    ActorWidget->SetActor(SketchActor);
}