#include "Tools/Sketch/SlateActorWidget.h"
#include "SlateOptMacros.h"


// TOMORROW: Hook Actor translation into widget.
// Should be done in Construct? Other events?
// Probably should be done when Actor is changed:
// This will need to be done when binding data to list view item.
// When Actor is changed, do we want to destroy the previous actor?


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SActorWidget::Construct(const FArguments& InArgs) {
    Actor = InArgs._Actor;
    UpdateActorLocation();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SActorWidget::UpdateActorLocation() {
    if(Actor != nullptr) {
        FVector2D WidgetLocation { GetPaintSpaceGeometry().GetAbsolutePosition() };
        FVector NewLocation { FVector(WidgetLocation[0], WidgetLocation[1], 0.0) };
        Actor->SetActorLocation(NewLocation);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Could not move: null Actor"));
    }
}