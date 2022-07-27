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
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  AActor* Actor { nullptr };

protected:
  virtual TSharedRef<SWidget> RebuildWidget() override;
  TSharedPtr<SActorWidget> ActorWidget;

};