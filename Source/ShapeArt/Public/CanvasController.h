#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Commands/CanvasCommand.h"
#include "History.h"
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

	void RunCommand(TScriptInterface<ICanvasCommand> Command) { GetGameState()->RunCommand(Command); }

	void SetupMouseInput();
	
public:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Undo();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Redo();

};
