#pragma once

#include "CoreMinimal.h"
#include "PolySet.generated.h"


UCLASS(BlueprintType)
class SHAPEART_API UPolySet : public UObject {

	GENERATED_BODY()

	public:

	UPolySet() {}

	UFUNCTION(BlueprintCallable)
	FPolyData GetData(int Index);

};