#include "PolyAdapter.h"

UPolyAdapter::UPolyAdapter() {
    FPolySet* Set { NewObject<FPolySet>() };
    Sets.Add(Set);
}

int UPolyAdapter::SetCount() {
    return Sets.Num();
}

FPolySet* UPolyAdapter::GetSet(int Index) {
    return Sets[Index];
}