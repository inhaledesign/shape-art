#pragma once

#include "CoreMinimal.h"
#include "SketchData.generated.h"


// ListView will only use data object that are classes. Structs do not work. /shrug

UCLASS(Blueprintable)
class SHAPEART_API USketchData : public UObject {

	GENERATED_BODY()

public:

    USketchData() {}

	UPROPERTY(BlueprintReadOnly)
	FString Label { FString("TESSST") };

};