#include "PolyAdapter.h"

UPolyAdapter::UPolyAdapter() {
    UPolySet* NewSet { NewObject<UPolySet>() };
    Sets.Add(NewSet);
}

int UPolyAdapter::SetCount() {
    return Sets.Num();
}

UPolySet* UPolyAdapter::GetSet(int Index) {
    return Sets[Index];
}