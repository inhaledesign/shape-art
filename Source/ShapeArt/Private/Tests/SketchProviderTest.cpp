#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "SketchProvider.h"
#include "Tools/Sketch/SketchData.h"
#include "SlateCore.h"
#include "Widgets/Views/SListView.h"


BEGIN_DEFINE_SPEC(FSketchProviderTest, "ShapeArt.SketchProvider", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

	typedef SListView<UObject*> MockListView;
    TSharedPtr<MockListView> ListViewPtr;
    FSketchProvider Provider { FSketchProvider() };

    void TestListViewItemsObservedNumEquals(int Num) {
        TestEqual("has right size", ListViewPtr->GetNumItemsBeingObserved(), Num);
    }

    void AddData() {
        UObject* NewDatum { NewObject<USketchData>() };
        Provider.Data.Emplace( NewDatum );
    }

END_DEFINE_SPEC(FSketchProviderTest)

void FSketchProviderTest::Define() {
    BeforeEach([this]() {
        ListViewPtr = SNew(MockListView)
            .ListItemsSource(&Provider.Data);
    });

    It("Add Data to ListView", [this]() {
        TestListViewItemsObservedNumEquals(0);
        AddData();
        TestListViewItemsObservedNumEquals(1);
        AddData();
        TestListViewItemsObservedNumEquals(2);
    });

}