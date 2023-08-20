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

void ACanvasController::AddPoly(UPolyComponent *Poly, FVector Location, APolyGroupActor *Canvas) {
    UAddPolyCommand* Command { NewObject<UAddPolyCommand>() };
    Command->Location = Location;
    Command->Vertices = Poly->Vertices;
    GetGameState()->RunCommand(Command, Canvas);
}