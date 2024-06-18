// Author: Antonio Sidenko (Tonetfal), May 2024

#pragma once

#include "Engine/DataAsset.h"

#include "SlateNavigationProfile.generated.h"

USTRUCT(BlueprintType)
struct FSlateNavigationProfile
{
	GENERATED_BODY()

public:
	FSlateNavigationProfile();

public:
	/** Should the Tab key perform next and previous style navigation? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bTabNavigation;

	/** Should we respect keys for navigation? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bKeyNavigation;

	/** Digital key navigation rules. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bKeyNavigation"))
	TMap<FKey, EUINavigation> KeyEventRules;

	/** Should we respect the analog stick for navigation? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bAnalogNavigation;

	/** Which Axis Key controls horizontal navigation */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	FKey AnalogHorizontalKey;

	/** Which Axis Key controls vertical navigation */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	FKey AnalogVerticalKey;

	/** Minimum analog value on the horizontal axes should have to perform navigation. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	float AnalogNavigationHorizontalThreshold;

	/** Minimum analog value on the vertical axis should have to perform navigation. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	float AnalogNavigationVerticalThreshold;

	/** Keys used to trigger a native action. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TMap<FKey, EUINavigationAction> KeyActions;
};

UCLASS(Blueprintable, BlueprintType, MinimalAPI)
class USlateNavigationProfileAsset
	: public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FSlateNavigationProfile Data;
};
