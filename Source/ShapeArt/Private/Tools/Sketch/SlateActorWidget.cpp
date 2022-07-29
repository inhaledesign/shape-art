#include "Tools/Sketch/SlateActorWidget.h"
#include "SlateOptMacros.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SActorWidget::Construct(const FArguments& InArgs) {

    
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SActorWidget::SetActor(AActor* InActor) {
    Actor = InActor;
    UpdateActorLocation();
}

void SActorWidget::UpdateActorLocation() {
    if(Actor != nullptr) {
        FVector2D WidgetLocation { GetPaintSpaceGeometry().GetAbsolutePosition() };
        FVector NewLocation { FVector(WidgetLocation[0], WidgetLocation[1], 0.0) };
        Actor->SetActorLocation(NewLocation);
    }
}