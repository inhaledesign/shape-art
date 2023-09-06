

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PolySet.generated.h"


USTRUCT(BlueprintType)
struct SHAPEART_API FPolySet {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name { "Basic" };
};
