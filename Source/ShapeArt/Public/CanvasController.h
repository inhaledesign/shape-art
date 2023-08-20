#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Commands/CanvasCommand.h"
#include "Commands/CommandHistory.h"
#include "Commands/AddPolyCommand.h"
#include "CanvasGameState.h"
#include "PolyComponent.h"
#include "CanvasController.generated.h"

 
UCLASS()
class SHAPEART_API ACanvasController : public APlayerController
{
	GENERATED_BODY()

	ACanvasGameState* GetGameState() {
		UWorld* World = GetWorld();
		return Cast<ACanvasGameState>(UGameplayStatics::GetGameState(World));
	}

	void RunCommand(ICanvasCommand* Command, APolyGroupActor* Canvas) { GetGameState()->RunCommand(Command, Canvas); }

	void SetupMouseInput();
	
public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Undo(APolyGroupActor* Canvas) { GetGameState()->Undo(Canvas); }

	UFUNCTION(BlueprintCallable)
	void Redo(APolyGroupActor* Canvas) { GetGameState()->Redo(Canvas); }

	UFUNCTION(BlueprintCallable)
	void AddPoly(UPolyComponent* Poly, FVector Location, APolyGroupActor* Canvas);

};
