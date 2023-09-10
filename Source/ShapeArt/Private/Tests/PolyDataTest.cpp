#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "PolyData.h"

BEGIN_DEFINE_SPEC(FPolyDataTest, "ShapeArt.PolyData", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter )

    FPolyData Data { FPolyData() };

END_DEFINE_SPEC(FPolyDataTest)

void FPolyDataTest::Define() {
    It("Initialize", [this] {
        TArray<FVector> Vertices = Data.Vertices;
    });
}