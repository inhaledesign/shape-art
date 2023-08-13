#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PolyComponent.h"
#include "PolyGroupActor.generated.h"

UCLASS()
class SHAPEART_API APolyGroupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APolyGroupActor();
	
	UFUNCTION(BlueprintCallable)
	bool AddPoly(const UPolyComponent* Poly);
	
};
