#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "History.h"
#include "Commands/SketchCommand.h"
#include "SketchGameState.generated.h"


UCLASS()
class SHAPEART_API ASketchGameState : public AGameStateBase {
	GENERATED_BODY()

	THistory<UObject*> History {};

	void UpdateHistoryHeadAndTailState();
	
public:

	UFUNCTION(BlueprintCallable)
	bool IsHistoryAtHead() { return History.IsHead(); }

	UFUNCTION(BlueprintCallable)
	bool IsHistoryAtTail() { return History.IsTail(); }

	void RunCommand(const TScriptInterface<ISketchCommand>& Command);
	
	void Undo();
	
	void Redo();

};
