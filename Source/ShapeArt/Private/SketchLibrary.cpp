#include "SketchLibrary.h"
#include "CoreMinimal.h"
#include "SketchActor.h"
#include "PolygonSketch.h"
#include "Kismet/GameplayStatics.h"


void USketchLibrary::RemoveAllSketchesFromWorld(UObject* WorldContext) {
    UWorld* World { WorldContext->GetWorld() };
    TArray<AActor*> Actors;
    UGameplayStatics::GetAllActorsOfClass(World, ASketchActor::StaticClass(), Actors);
    for (AActor* Actor : Actors) {
        Actor->Destroy();
    }
}