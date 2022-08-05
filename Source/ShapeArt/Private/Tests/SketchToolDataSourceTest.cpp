#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "SketchActor.h"
#include "Tools/Sketch/SketchToolDataSource.h"
#include "Tools/Sketch/SketchData.h"
#include "Tools/Sketch/SActorWidget.h"
#include "SlateCore.h"
#include "Widgets/Views/SListView.h"
#include "PolygonSketch.h"
#include "Tests/OpenTestMap.h"


// TODO: Update test to include world to spawn actors into.
// Want to figure out how to reuse specs, since this seems to be a common theme.

BEGIN_DEFINE_SPEC(FSketchToolDataSourceTest, "ShapeArt.SketchToolDataSource", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

	typedef SListView<UObject*> MockListView;
    TSharedPtr<MockListView> ListViewPtr { nullptr };
    USketchToolDataSource* DataSource { NewObject<USketchToolDataSource>() };
    FString MapName { TEXT("Canvas2D") };
    UWorld* World { nullptr };

    void TestListViewItemsObservedNumEquals(int Num) {
        TestEqual("has right size", ListViewPtr->GetNumItemsBeingObserved(), Num);
    }

    void AddData() {
        UObject* NewDatum { NewObject<USketchData>() };
        DataSource->Data.Emplace( NewDatum );
    }

END_DEFINE_SPEC(FSketchToolDataSourceTest)

void FSketchToolDataSourceTest::Define() {
    BeforeEach([this]() {
        ListViewPtr = SNew(MockListView)
            .ListItemsSource(&(DataSource->Data));
    });

    It("Add Data to ListView", [this]() {
        TestListViewItemsObservedNumEquals(0);
        AddData();
        TestListViewItemsObservedNumEquals(1);
        AddData();
        TestListViewItemsObservedNumEquals(2);
    });

    It("Bind to ActorWidget", [this]() {
        World = OpenTestMap(MapName);
        USketchData* Datum = NewObject<USketchData>();
        TSharedPtr<SActorWidget> ActorWidget { SNew(SActorWidget) };
        
        ASketchActor* SketchActor { World->SpawnActor<ASketchActor>() };
        DataSource->BindData(Datum, ActorWidget, SketchActor);
        TestNotNull("ActorWidget Actor reference", ActorWidget->GetActor());
    });
}