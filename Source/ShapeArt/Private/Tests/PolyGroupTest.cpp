#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "PolyGroupActor.h"
#include "Tests/OpenTestMap.h"


BEGIN_DEFINE_SPEC(FPolyGroupActorTest, "ShapeArt.PolyGroupActor", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter )
    
    UWorld* World { nullptr };
    APolyGroupActor* PolyGroup { nullptr };
    FVector Location { FVector(0, 0, 0) };
    FRotator Rotation { FRotator(0, 0, 0) };
    FActorSpawnParameters SpawnInfo;

    int ComponentCount(TSubclassOf<UActorComponent> ComponentClass);

END_DEFINE_SPEC(FPolyGroupActorTest)

void FPolyGroupActorTest::Define() {
    BeforeEach([this]() {
        World = OpenTestMap("2DCanvas");
        PolyGroup = World->SpawnActor<APolyGroupActor>(Location, Rotation, SpawnInfo);
    });

    It("Initialize", [this]() {
        int N { ComponentCount(UActorComponent::StaticClass()) };
        TestEqual("Component count", N, 0);
    });

    It("Add PolyComponent", [this]() {
        UPolyComponent* Poly { NewObject<UPolyComponent>() };

        for(int i = 1; i <= 10; i++) {
            PolyGroup->AddPoly(Poly);
            int N { ComponentCount(UPolyComponent::StaticClass()) };
            TestEqual("PolyComponent count", N, i);
        }
    });

}

int FPolyGroupActorTest::ComponentCount(TSubclassOf<UActorComponent> ComponentClass) {
    return PolyGroup->GetComponentsByClass(ComponentClass).Num();
}