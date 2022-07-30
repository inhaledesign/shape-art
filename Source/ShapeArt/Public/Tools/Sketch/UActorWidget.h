#pragma once

#include "SActorWidget.h"
#include "Components/Widget.h"
#include "UActorWidget.generated.h"

UCLASS()
class SHAPEART_API UActorWidget : public UWidget
{
  
  GENERATED_BODY()

public:
  virtual void ReleaseSlateResources(bool bReleaseChildren) override;

  UFUNCTION(BlueprintCallable)
  void UpdateActorLocation();

protected:
  
  TSharedPtr<SActorWidget> ActorWidget;

  virtual TSharedRef<SWidget> RebuildWidget() override;


  friend class USketchToolDataSource;
};