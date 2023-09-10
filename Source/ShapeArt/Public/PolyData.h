

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PolyData.generated.h"


USTRUCT(BlueprintType)
struct FPolyData {

	GENERATED_BODY()
	
	
	public:

	UPROPERTY(BlueprintReadOnly)
	TArray<FVector> Vertices;

	FPolyData() { 
		Vertices.Add(FVector(-20, -20, 0));
		Vertices.Add(FVector(-20, 20, 0));
		Vertices.Add(FVector(20, 20, 0));
		Vertices.Add(FVector(20, -20, 0));
	}
};
