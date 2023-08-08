#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShapeArtGameMode.generated.h"


UCLASS()
class SHAPEART_API AShapeArtGameMode : public AGameModeBase
{
	GENERATED_BODY()

	void SetupDefaultClasses();

	void SetupPrimaryActorProperties();
	
	void SetupWorldProperties();

public:
	AShapeArtGameMode();
};
