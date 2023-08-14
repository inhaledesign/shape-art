#include "ShapeArtGameMode.h"
#include "CanvasController.h"
#include "CanvasGameState.h"

AShapeArtGameMode::AShapeArtGameMode() {
    SetupDefaultClasses();
    SetupPrimaryActorProperties();
    SetupWorldProperties();
}

void AShapeArtGameMode::SetupDefaultClasses() {
    PlayerControllerClass = ACanvasController::StaticClass();
    GameStateClass = ACanvasGameState::StaticClass();
}

void AShapeArtGameMode::SetupPrimaryActorProperties() {
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
}

void AShapeArtGameMode::SetupWorldProperties() {
    bPauseable = false;
    bUseSeamlessTravel = false;
}