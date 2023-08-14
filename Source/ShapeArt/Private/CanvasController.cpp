#include "CanvasController.h"
#include "CanvasGameState.h"
#include "Kismet/GameplayStatics.h"


void ACanvasController::BeginPlay() {
    Super::BeginPlay();
    SetupMouseInput();
}

void ACanvasController::SetupMouseInput() {
    SetInputMode(FInputModeGameAndUI());
    bShowMouseCursor = true;
    bEnableClickEvents = true;
}

void ACanvasController::Undo_Implementation() { GetGameState()->Undo();}

void ACanvasController::Redo_Implementation() { GetGameState()->Redo(); }