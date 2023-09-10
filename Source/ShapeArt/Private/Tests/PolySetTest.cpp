#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "PolySet.h"
#include "PolyData.h"

BEGIN_DEFINE_SPEC(FPolySetTest, "ShapeArt.PolySet", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter )

    UPolySet* Set { nullptr };

END_DEFINE_SPEC(FPolySetTest)

void FPolySetTest::Define() {
    BeforeEach([this]() {
        Set = NewObject<UPolySet>();
    });
    It("Initialize", [this] {
        FPolyData PolyData { Set->GetData(0) };
    });
}