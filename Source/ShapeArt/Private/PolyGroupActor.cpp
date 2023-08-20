#include "PolyGroupActor.h"


APolyGroupActor::APolyGroupActor() {
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

bool APolyGroupActor::AddPoly(const UPolyComponent *Poly, const FVector WorldLocation) {
	const bool ManualAttachment = false;
	FTransform Transform { FTransform() };
	UPolyComponent* NewPoly { (UPolyComponent*) AddComponentByClass(UPolyComponent::StaticClass(), ManualAttachment, Transform, true) };

	if(Poly && NewPoly) {
		NewPoly->Copy(Poly);
		FinishAddComponent(NewPoly, ManualAttachment, Transform);
		NewPoly->SetWorldLocation(WorldLocation);
		return true;
	}
	else { return false; }
}

UPolyComponent* APolyGroupActor::AddPolyByVertices(TArray<FVector> Vertices, const FVector WorldLocation) {
	const bool ManualAttachment = false;
	FTransform Transform { FTransform() };
	UPolyComponent* NewPoly { (UPolyComponent*) AddComponentByClass(UPolyComponent::StaticClass(), ManualAttachment, Transform, true) };

	if(NewPoly) {
		NewPoly->Vertices = Vertices;
		FinishAddComponent(NewPoly, ManualAttachment, Transform);
		NewPoly->SetWorldLocation(WorldLocation);
		return NewPoly;
	}

	return nullptr;	
}
