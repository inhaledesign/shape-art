#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PolySet.h"
#include "PolyAdapter.generated.h"


UCLASS(BlueprintType)
class SHAPEART_API UPolyAdapter : public UObject
{

	GENERATED_BODY()

	TArray<UPolySet*> Sets;
	
	public:

	UPolyAdapter();

	UFUNCTION(BlueprintCallable)
	int SetCount();

	UFUNCTION(BlueprintCallable)
	UPolySet* GetSet(int Index);
};
