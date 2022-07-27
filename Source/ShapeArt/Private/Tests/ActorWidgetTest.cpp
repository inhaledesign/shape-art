#include "Tools/Sketch/SlateActorWidget.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/OpenTestMap.h"
#include "SketchActor.h"

BEGIN_DEFINE_SPEC(FActorWidgetTest, "ShapeArt.ActorWidget", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
    UWorld* World { nullptr };
    FVector Location { FVector(30, 20, 0) };
    FRotator Rotation { FRotator() };
    FActorSpawnParameters SpawnParams { FActorSpawnParameters() };
    FString MapName { TEXT("Canvas2D") };
END_DEFINE_SPEC(FActorWidgetTest)

void FActorWidgetTest::Define() {
    BeforeEach([this]() {
        World = OpenTestMap(MapName);
    });

    It("Actor Sticks On Construct", [this]() {
        AActor* Actor = World->SpawnActor<ASketchActor>(Location, Rotation, SpawnParams);
        TSharedPtr<SActorWidget> ActorWidget = SNew(SActorWidget)
            .Actor(Actor);
        GEngine->GameViewport->AddViewportWidgetContent(ActorWidget.ToSharedRef());
        FGeometry Geometry { ActorWidget->GetPaintSpaceGeometry() };
        FVector2D Position { Geometry.GetAbsolutePosition() };

        FVector ActorLocation = Actor->GetActorLocation();

        TestEqual("Actor Location X", ActorLocation[0], Position[0]);
        TestEqual("Actor Location Y", ActorLocation[1], Position[1]);
    });

} 