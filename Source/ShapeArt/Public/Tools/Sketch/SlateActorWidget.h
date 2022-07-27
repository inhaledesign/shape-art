#pragma once

#include "Widgets/SCompoundWidget.h"


// TODO: Should be LeafWidget?
class SHAPEART_API SActorWidget : public SCompoundWidget {
public:
  SLATE_BEGIN_ARGS(SActorWidget) {}

    // TODO: If this is an Attribute, we can pass a function in
    // that creates an actor. Maybe worth it?
    SLATE_ARGUMENT(AActor*, Actor)

  SLATE_END_ARGS()

  void Construct(const FArguments& InArgs);

  void UpdateActorLocation();

protected:
    AActor* Actor { nullptr };
    
};