

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PolySet.h"
#include "PolyAdapter.generated.h"


UCLASS(BlueprintType)
class SHAPEART_API UPolyAdapter : public UObject
{

	GENERATED_BODY()

	TArray<UPolySet*> Sets { TArray<UPolySet*>() };
	
	public:

	UPolyAdapter();

	int SetCount();

	UPolySet* GetSet(int Index);
};
