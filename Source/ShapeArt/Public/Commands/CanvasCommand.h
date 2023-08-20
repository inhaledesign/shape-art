#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PolyGroupActor.h"
#include "CanvasCommand.generated.h"


UINTERFACE(MinimalAPI)
class UCanvasCommand : public UInterface {

	GENERATED_BODY()

};


class ICanvasCommand {
	
	GENERATED_BODY()

public:
	
	virtual void Execute(APolyGroupActor* Canvas) = 0;

	virtual void Undo(APolyGroupActor* Canvas) 	= 0;
	
};
