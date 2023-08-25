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
    bEnableTouchEvents = true;
    
    FInputModeGameAndUI inputMode;
	inputMode.SetHideCursorDuringCapture(false);
	SetInputMode(inputMode);
}

void ACanvasController::AddPoly(UPolyComponent *Poly, FVector Location, APolyGroupActor *Canvas) {
    UAddPolyCommand* Command { NewObject<UAddPolyCommand>() };
    Command->Location = Location;
    Command->Vertices = Poly->Vertices;
    GetGameState()->RunCommand(Command, Canvas);
}

bool ACanvasController::GetMouseLocation(FVector& MouseLocation, float CameraDistance) {
    FVector Location { FVector() };
    FVector Direction { FVector() };

    const bool Success { DeprojectMousePositionToWorld(Location, Direction) };

    if(Success) {
        Direction *= CameraDistance;
        MouseLocation = Location + Direction;
    }
    
    return Success;

}