#include "Tools/Sketch/SlateActorWidget.h"
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
        FVector2D WidgetTopLeft { USlateBlueprintLibrary::GetLocalTopLeft(GetPaintSpaceGeometry()) };
        FVector2D WidgetLocation { FVector2D() };
        FVector2D PixelLocation { FVector2D() }; // Don't need this, but we can't pass nullptr
        FVector WorldLocation { FVector() };
        FVector WorldDirection { FVector() };


        USlateBlueprintLibrary::LocalToViewport(Actor->GetWorld(), GetPaintSpaceGeometry(), WidgetTopLeft, PixelLocation, WidgetLocation);
        APlayerController* Controller { UGameplayStatics::GetPlayerController(Actor->GetWorld(), 0) };
        Controller->DeprojectScreenPositionToWorld(WidgetLocation[0], WidgetLocation[1], WorldLocation, WorldDirection);
        
        Actor->SetActorLocation(WorldLocation);
    }
}