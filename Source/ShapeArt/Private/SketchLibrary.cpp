#include "SketchLibrary.h"
#include "CoreMinimal.h"
#include "SketchActor.h"
#include "PolygonSketch.h"
#include "Kismet/GameplayStatics.h"


ASketchActor* USketchLibrary::AddTriangleToWorld(UObject* WorldContext) {
    UWorld* World { WorldContext->GetWorld() };
    FVector Location { 0, 0, 0 };
    FRotator Rotation { 0, 0, 0 };
    ASketchActor* SketchActor = AddSketchActorToWorld(World, Location, Rotation);
    SketchActor->AddTriangleMesh();
    return SketchActor;
}

ASketchActor* USketchLibrary::AddSketchActorToWorld(UWorld* World, FVector const& Location, FRotator const& Rotation) {
    if(World != nullptr) {
        const FActorSpawnParameters SpawnParams { };
        return (ASketchActor*) World->SpawnActor(ASketchActor::StaticClass(), &Location, &Rotation, SpawnParams);
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Cannot add Sketch. Pointer to World was null."));
        throw "Failed to add Sketch.";
    }
}

void USketchLibrary::RemoveAllSketchesFromWorld(UObject* WorldContext) {
    UWorld* World { WorldContext->GetWorld() };
    TArray<AActor*> Actors;
    UGameplayStatics::GetAllActorsOfClass(World, ASketchActor::StaticClass(), Actors);
    for (AActor* Actor : Actors) {
        Actor->Destroy();
    }
}