#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Commands/SketchCommand.h"
#include "History.h"
#include "SketchGameState.h"
#include "PolyComponent.h"
#include "SketchController.generated.h"

 
UCLASS()
class SHAPEART_API ASketchController : public APlayerController
{
	GENERATED_BODY()

	ASketchGameState* GetGameState() {
		UWorld* World = GetWorld();
		return Cast<ASketchGameState>(UGameplayStatics::GetGameState(World));
	}

	void RunCommand(TScriptInterface<ISketchCommand> Command) { GetGameState()->RunCommand(Command); }

	void SetupMouseInput();
	
public:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Undo();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Redo();

};
