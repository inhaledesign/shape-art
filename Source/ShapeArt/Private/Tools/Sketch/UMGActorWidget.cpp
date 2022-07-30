#include "Tools/Sketch/UMGActorWidget.h"


void UActorWidget::ReleaseSlateResources(bool bReleaseChildren) {
  ActorWidget.Reset();
}

TSharedRef<SWidget> UActorWidget::RebuildWidget() {
  ActorWidget = SNew(SActorWidget);
  return ActorWidget.ToSharedRef();
}

void UActorWidget::UpdateActorLocation() {
  if(ActorWidget != nullptr) {
    ActorWidget->UpdateActorLocation();
  }
}