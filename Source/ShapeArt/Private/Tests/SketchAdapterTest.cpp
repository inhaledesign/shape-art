#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "SketchAdapter.h"
#include "SlateCore.h"
#include "Widgets/Views/SListView.h"
#include "Templates/SharedPointer.h"


BEGIN_DEFINE_SPEC(FSketchAdapterTest, "ShapeArt.SketchAdapter", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
    
    TArray<USketchAdapter::FTextPointer> Labels { TArray<USketchAdapter::FTextPointer>() };
    USketchAdapter* Adapter { NewObject<USketchAdapter>() };

    void AddText(FString Str) {
        Labels.Add(MakeShared<FText>(FText::FromString(Str)));
    }

END_DEFINE_SPEC(FSketchAdapterTest)

void FSketchAdapterTest::Define() {
    BeforeEach([this]() {
        AddText("Test A");
    });

    It("Fill ListView With Adapter", [this]() {
        TSharedRef<USketchAdapter::FTextListView> ListViewRef = SNew(USketchAdapter::FTextListView);
        Adapter->SetData(Labels);
        Adapter->SetListView(ListViewRef);
        Adapter->Update();
        TestEqual("has right size", ListViewRef.Get().GetNumItemsBeingObserved(), Labels.Num());
    });

}