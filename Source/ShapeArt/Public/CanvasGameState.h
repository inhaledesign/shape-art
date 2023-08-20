#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Commands/CommandHistory.h"
#include "Commands/CanvasCommand.h"
#include "PolyGroupActor.h"
#include "CanvasGameState.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHistoryChangedEvent);

UCLASS()
class SHAPEART_API ACanvasGameState : public AGameStateBase {
	
	GENERATED_BODY()

	UCommandHistory* History { NewObject<UCommandHistory>() };

	UPROPERTY(BlueprintAssignable)
	FHistoryChangedEvent HistoryChangedEvent;
	
public:	

	UFUNCTION(BlueprintCallable)
	bool IsHistoryAtHead() { return History->UndoCount() == 0; }

	UFUNCTION(BlueprintCallable)
	bool IsHistoryAtTail() { return History->RedoCount() == 0; }

	void RunCommand(ICanvasCommand* Command, APolyGroupActor* Canvas);
	
	void Undo(APolyGroupActor* Canvas);
	
	void Redo(APolyGroupActor* Canvas);



};
