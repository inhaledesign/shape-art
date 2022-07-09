#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tools/Sketch/SketchToolDataSource.h"
#include "Tools/Sketch/SketchData.h"
#include "SlateCore.h"
#include "Widgets/Views/SListView.h"


BEGIN_DEFINE_SPEC(FSketchToolDataSourceTest, "ShapeArt.SketchToolDataSource", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

	typedef SListView<UObject*> MockListView;
    TSharedPtr<MockListView> ListViewPtr { nullptr };
    USketchToolDataSource* Source { NewObject<USketchToolDataSource>() };

    void TestListViewItemsObservedNumEquals(int Num) {
        TestEqual("has right size", ListViewPtr->GetNumItemsBeingObserved(), Num);
    }

    void AddData() {
        UObject* NewDatum { NewObject<USketchData>() };
        Source->Data.Emplace( NewDatum );
    }

END_DEFINE_SPEC(FSketchToolDataSourceTest)

void FSketchToolDataSourceTest::Define() {
    BeforeEach([this]() {
        ListViewPtr = SNew(MockListView)
            .ListItemsSource(&(Source->Data));
    });

    It("Add Data to ListView", [this]() {
        TestListViewItemsObservedNumEquals(0);
        AddData();
        TestListViewItemsObservedNumEquals(1);
        AddData();
        TestListViewItemsObservedNumEquals(2);
    });

}