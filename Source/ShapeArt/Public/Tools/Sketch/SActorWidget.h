#pragma once

#include "Widgets/SCompoundWidget.h"


// TODO: Should be LeafWidget?
class SHAPEART_API SActorWidget : public SCompoundWidget {

    AActor* Actor { nullptr };
    
public:
  SLATE_BEGIN_ARGS(SActorWidget) {}

  SLATE_END_ARGS()

  void Construct(const FArguments& InArgs);

  void SetActor(AActor* InActor);

  AActor* GetActor() { return Actor; }

  void UpdateActorLocation();

private:

  FVector2D GetWidgetViewportLocation();

  FVector GetDeprojectedLocation(FVector2D WidgetLocation);
};