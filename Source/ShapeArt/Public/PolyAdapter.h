

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PolySet.h"
#include "PolyAdapter.generated.h"


UCLASS(BlueprintType)
class SHAPEART_API UPolyAdapter : public UObject
{

	GENERATED_BODY()

	TArray<FPolySet*> Sets { TArray<FPolySet*>() };
	
	public:

	UPolyAdapter();

	int SetCount();

	FPolySet* GetSet(int Index);
};
