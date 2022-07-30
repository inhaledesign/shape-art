#include "Tools/Sketch/SlateActorWidget.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/OpenTestMap.h"
#include "SketchActor.h"
#include "Widgets/SBoxPanel.h"

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

    It("Actor Sticks To Widget on Set", [this]() {
        AActor* Actor { World->SpawnActor<ASketchActor>(Location, Rotation, SpawnParams) };
        TSharedPtr<SActorWidget> ActorWidget = SNew(SActorWidget);

        ActorWidget->SetActor(Actor);

        TSharedPtr<SHorizontalBox> CanvasWidget = SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
            .HAlign(HAlign_Center)
            .VAlign(VAlign_Center)
            .Padding(10)
            [ ActorWidget.ToSharedRef() ];
            
        GEngine->GameViewport->AddViewportWidgetContent(CanvasWidget.ToSharedRef());
        FGeometry WidgetGeometry { ActorWidget->GetPaintSpaceGeometry() };
        FVector2D WidgetPosition { WidgetGeometry.GetAbsolutePosition() };

        FVector ActorLocation = Actor->GetActorLocation();

        TestEqual("Actor Location X", ActorLocation[0], WidgetPosition[0]);
        TestEqual("Actor Location Y", ActorLocation[1], WidgetPosition[1]);
    });
} 