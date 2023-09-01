#include "PolyAdapter.h"

UPolyAdapter::UPolyAdapter() {
    UPolySet* Set { NewObject<UPolySet>() };
    Sets.Add(Set);
}

int UPolyAdapter::SetCount() {
    return Sets.Num();
}

UPolySet* UPolyAdapter::GetSet(int Index) {
    return Sets[Index];
}