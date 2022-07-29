#pragma once

#include "CoreMinimal.h"
#include "SketchActor.h"
#include "Tools/Sketch/SketchData.h"
#include "Tools/Sketch/UMGActorWidget.h"
#include "Tools/Sketch/SlateActorWidget.h"
#include "SketchToolDataSource.generated.h"


UCLASS(Blueprintable)
class SHAPEART_API USketchToolDataSource: public UObject
{
	GENERATED_BODY()

	public:

	USketchToolDataSource() {}
	
	// TODO: Can we make this Private and then specify a public getter in the metadata?
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UObject*> Data { TArray<UObject*>() };

	UFUNCTION(BlueprintCallable)
	void BindData(USketchData* SketchData, UActorWidget* UActorWidget, ASketchActor* SketchActor) {
		BindData(SketchData, UActorWidget->ActorWidget, SketchActor);
	};

	void BindData(USketchData* SketchData, TSharedPtr<SActorWidget> ActorWidget, ASketchActor* SketchActor);
	
};