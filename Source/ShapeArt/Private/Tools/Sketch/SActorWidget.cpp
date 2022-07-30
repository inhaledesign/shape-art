#include "Tools/Sketch/SActorWidget.h"
#include "SlateOptMacros.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SActorWidget::Construct(const FArguments& InArgs) {

    
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SActorWidget::SetActor(AActor* InActor) {
    if(Actor != nullptr) {
        Actor->Destroy();
    }
    Actor = InActor;
}

void SActorWidget::UpdateActorLocation() {
    if(Actor != nullptr) {
        FVector2D WidgetLocation { GetWidgetViewportLocation() };
        FVector WorldLocation { GetDeprojectedLocation(WidgetLocation) };
        Actor->SetActorLocation(WorldLocation);
    }
}

FVector2D SActorWidget::GetWidgetViewportLocation() {
    FGeometry Geometry { GetPaintSpaceGeometry() };
    UWorld* World { Actor->GetWorld() };
    FVector2D WidgetLocation { FVector2D() };
    FVector2D PixelLocation { FVector2D() };
    FVector2D WidgetTopLeft { USlateBlueprintLibrary::GetLocalTopLeft(Geometry) };
    
    USlateBlueprintLibrary::LocalToViewport(
        World, 
        Geometry, 
        WidgetTopLeft, 
        PixelLocation, //  // not using, but have to pass something
        WidgetLocation);

    return WidgetLocation;
}

FVector SActorWidget::GetDeprojectedLocation(FVector2D WidgetLocation) {
    FVector WorldLocation { FVector() };
    FVector WorldDirection { FVector() };
    UWorld* World { Actor->GetWorld() };
    APlayerController* Controller { UGameplayStatics::GetPlayerController(World, 0) };

    Controller->DeprojectScreenPositionToWorld(
        WidgetLocation[0],
        WidgetLocation[1],
        WorldLocation,
        WorldDirection); // not using, but have to pass something
    
    return WorldLocation;
}