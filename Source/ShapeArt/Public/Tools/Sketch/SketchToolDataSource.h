#pragma once

#include "CoreMinimal.h"
#include "SketchData.h"
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
	
};