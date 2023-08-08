#include "SketchController.h"
#include "SketchGameState.h"
#include "Commands/AddTriangleCommand.h"
#include "Kismet/GameplayStatics.h"


void ASketchController::BeginPlay() {
    Super::BeginPlay();
    SetupMouseInput();
}

void ASketchController::SetupMouseInput() {
    SetInputMode(FInputModeGameAndUI());
    bShowMouseCursor = true;
    bEnableClickEvents = true;
}

void ASketchController::Undo_Implementation() {
    GetGameState()->Undo();
}

void ASketchController::Redo_Implementation() {
    GetGameState()->Redo();
}

void ASketchController::AddTriangle_Implementation() {
    TScriptInterface<ISketchCommand> CommandInterface = NewObject<UAddTriangleCommand>();
    UAddTriangleCommand* Command = (UAddTriangleCommand*) CommandInterface.GetInterface();
    Command->SetLocation(0, 0);
    RunCommand(CommandInterface);
}