#pragma once

#include "SlateActorWidget.h"
#include "Components/Widget.h"
#include "UMGActorWidget.generated.h"

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