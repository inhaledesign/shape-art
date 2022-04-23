#include "ShapeArtGameMode.h"
#include "SketchController.h"
#include "SketchGameState.h"

AShapeArtGameMode::AShapeArtGameMode() {
    SetupDefaultClasses();
    SetupPrimaryActorProperties();
    SetupWorldProperties();
}

void AShapeArtGameMode::SetupDefaultClasses() {
    PlayerControllerClass = ASketchController::StaticClass();
    GameStateClass = ASketchGameState::StaticClass();
}

void AShapeArtGameMode::SetupPrimaryActorProperties() {
    PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;
    PrimaryActorTick.bAllowTickOnDedicatedServer = false;
}

void AShapeArtGameMode::SetupWorldProperties() {
    bPauseable = false;
    bUseSeamlessTravel = false;
}