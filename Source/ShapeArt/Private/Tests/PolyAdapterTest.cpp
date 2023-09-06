#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "PolyAdapter.h"

BEGIN_DEFINE_SPEC(FPolyAdapterTest, "ShapeArt.PolyAdapter", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter )
   
    UPolyAdapter* Adapter { nullptr };

END_DEFINE_SPEC(FPolyAdapterTest)

void FPolyAdapterTest::Define() {
    BeforeEach([this]() {
        Adapter = NewObject<UPolyAdapter>();
    });
    It("Set Count", [this] {
        int SetCount { Adapter->SetCount() };
        TestEqual("Count Equals 1", SetCount, 1);
    });
    It("Get Set", [this] {
        UPolySet* Set { Adapter->GetSet(0) };
        TestNotNull("Not null", Set);
        TestEqual("Name", "Basic", Set->Name);
    });
}