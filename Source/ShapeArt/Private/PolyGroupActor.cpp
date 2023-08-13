#include "PolyGroupActor.h"


APolyGroupActor::APolyGroupActor() {
	PrimaryActorTick.bCanEverTick = false;
}

bool APolyGroupActor::AddPoly(const UPolyComponent *Poly) {
	FTransform Transform { FTransform() };
	UPolyComponent* NewPoly { (UPolyComponent*) AddComponentByClass(UPolyComponent::StaticClass(), false, Transform, true) };
	
	if(Poly && NewPoly) {
		NewPoly->Copy(Poly);
		FinishAddComponent(NewPoly, false, Transform);
		return true;
	}
	else { return false; }
}