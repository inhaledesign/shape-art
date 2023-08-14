#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "History.h"
#include "Commands/CanvasCommand.h"
#include "CanvasGameState.generated.h"


UCLASS()
class SHAPEART_API ACanvasGameState : public AGameStateBase {
	GENERATED_BODY()

	THistory<UObject*> History {};

	void UpdateHistoryHeadAndTailState();
	
public:

	UFUNCTION(BlueprintCallable)
	bool IsHistoryAtHead() { return History.IsHead(); }

	UFUNCTION(BlueprintCallable)
	bool IsHistoryAtTail() { return History.IsTail(); }

	void RunCommand(const TScriptInterface<ICanvasCommand>& Command);
	
	void Undo();
	
	void Redo();

};
