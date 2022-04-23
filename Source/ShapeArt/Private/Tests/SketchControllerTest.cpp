#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Kismet/GameplayStatics.h"
#include "Tests/OpenTestMap.h"
#include "SketchActor.h"
#include "SketchController.h"
#include "SketchGameState.h"
#include "SketchLibrary.h"


BEGIN_DEFINE_SPEC(FSketchControllerTest, "ShapeArt.SketchController", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
    UWorld* World { nullptr };
    ASketchController* Controller { nullptr };
    ASketchGameState* GameState { nullptr };
 
    void AddTriangle(int Count = 1) {
        for(int i = 0; i < Count; i++) {
            Controller->AddTriangle();
        } 
    }

    void TestSketchActorCount(int ExpectedCount) {
        TArray<AActor*> Actors {};
        UGameplayStatics::GetAllActorsOfClass(World, ASketchActor::StaticClass(), Actors);
        int ActualCount = Actors.Num();
        TestEqual("Sketches in World", ActualCount, ExpectedCount);
    }

    void Undo(int Count = 1) {
        for(int i = 0; i < Count; i++){
            Controller->Undo(); 
        }
    }

    void Redo(int Count = 1) {
        for(int i = 0; i < Count; i++) {
            Controller->Redo(); 
        }
    }

    void TestIsHead() {
        bool IsHead = GameState->IsHistoryAtHead();
        TestEqual("is head", IsHead, true);
    }

    void TestIsTail() {
        bool IsTail = GameState->IsHistoryAtTail();
        TestEqual("is tail", IsTail, true);
    }
END_DEFINE_SPEC(FSketchControllerTest)

void FSketchControllerTest::Define() {
    BeforeEach([this]() {
        auto MapName { TEXT("Canvas2D") };
        World = OpenTestMap(MapName);
        Controller = (ASketchController*) World->GetFirstPlayerController();
        GameState = World->GetGameState<ASketchGameState>();
    });

    It("Add triangle", [this]() {
        AddTriangle();
        TestSketchActorCount(1);
        AddTriangle();
        TestSketchActorCount(2);
    });

    It("Undo", [this]() {
        AddTriangle(3);
        TestSketchActorCount(3);
        Undo();
        TestSketchActorCount(2);
        Undo();
        TestSketchActorCount(1);
        Undo();
        TestSketchActorCount(0);
    });

    It("Redo", [this]() {
        AddTriangle(3);
        Undo(3);
        Redo();
        TestSketchActorCount(1);
        Redo();
        TestSketchActorCount(2);
        Redo();
        TestSketchActorCount(3);
    });

    It("Undo / Redo Stress (traverse all commands)", [this]() {
        int CommandCount = 100;
        int StressAttempts = 50;
        AddTriangle(CommandCount);
        
        for(int i = 0; i < StressAttempts; i++) {
            Undo(CommandCount);
            TestSketchActorCount(0);
            TestIsHead();
            Redo(CommandCount);
            TestSketchActorCount(CommandCount);
            TestIsTail();
        }
    });

    
    It("Undo / Redo Stress (Undo 2, Redo 1 until head)", [this]() {
        int CommandCount = 100;
        AddTriangle(CommandCount);
        
        // Undo 2, Redo 1, until 1 before head
        for(int i = 0; i < CommandCount - 1; i++) {
            Undo(2);
            TestSketchActorCount(CommandCount - 2 - i);
            Redo(1);
            TestSketchActorCount(CommandCount - 1 - i);
        }

        // Undo once to get to the head
        Undo(1);
        TestIsHead();
    });
}