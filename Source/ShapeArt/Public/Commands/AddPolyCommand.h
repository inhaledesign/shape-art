#pragma once

#include "CoreMinimal.h"
#include "Commands/CanvasCommand.h"
#include "AddPolyCommand.generated.h"


UCLASS()
class SHAPEART_API UAddPolyCommand : public UObject, public ICanvasCommand {

	GENERATED_BODY()

	UPolyComponent* Poly { nullptr };

public:

	UAddPolyCommand() {}

    FVector Location;

    TArray<FVector> Vertices;

	virtual void Execute(APolyGroupActor* Canvas) override;

	virtual void Undo(APolyGroupActor* Canvas) override;

};