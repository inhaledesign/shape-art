#include "Tools/Sketch/SActorWidget.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/OpenTestMap.h"
#include "SketchActor.h"
#include "Widgets/SBoxPanel.h"

BEGIN_DEFINE_SPEC(FActorWidgetTest, "ShapeArt.ActorWidget", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
    UWorld* World { nullptr };
    FString MapName { TEXT("Canvas2D") };

    AActor* SpawnActor() {
        FVector Location { FVector(30, 20, 0) };
        FRotator Rotation { FRotator() };
        FActorSpawnParameters SpawnParams { FActorSpawnParameters() };
        return World->SpawnActor<ASketchActor>(Location, Rotation, SpawnParams);
    }

    void AddActorWidgetToScreen(TSharedPtr<SActorWidget> ActorWidget) {
        TSharedPtr<SHorizontalBox> CanvasWidget = SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
            .HAlign(HAlign_Left)
            .VAlign(VAlign_Top)
            [ ActorWidget.ToSharedRef() ];
        
        GEngine->GameViewport->AddViewportWidgetContent(CanvasWidget.ToSharedRef());
    }

END_DEFINE_SPEC(FActorWidgetTest)

void FActorWidgetTest::Define() {
    BeforeEach([this]() {
        World = OpenTestMap(MapName);
    });

    It("Actor Moves To Widget", [this]() {
        AActor* Actor { SpawnActor() };
        TSharedPtr<SActorWidget> ActorWidget = SNew(SActorWidget);
        ActorWidget->SetActor(Actor);
        AddActorWidgetToScreen(ActorWidget);
       
        ActorWidget->UpdateActorLocation();
        FVector ActorLocation = Actor->GetActorLocation();

        // This isn't an ideal test, but to be accurate we would have to figure out exactly where
        // the widget is and find that point in the world, which would be replicating the working code.
        TestNotEqual("Actor Location X", ActorLocation[0], 30.0);
        TestNotEqual("Actor Location Y", ActorLocation[1], 20.0);
    });
} 