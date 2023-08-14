#include "SketchController.h"
#include "SketchGameState.h"
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