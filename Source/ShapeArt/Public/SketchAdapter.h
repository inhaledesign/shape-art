

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SketchAdapter.generated.h"


UCLASS()
class SHAPEART_API USketchAdapter : public UObject
{
	GENERATED_BODY()

	public:
	
	typedef TSharedPtr<FText> FTextPointer; 
	typedef SListView<FTextPointer> FTextListView;

	private:

	TArray<FTextPointer>* Labels { nullptr };
	TSharedRef<FTextListView>* ListView { nullptr };

	public:
	
	USketchAdapter() {}

	void SetData(TArray<FTextPointer>& InLabels) { Labels = &InLabels; }

	void SetListView(TSharedRef<FTextListView>& InListView) { this->ListView = &InListView; }

	void Update();

};
