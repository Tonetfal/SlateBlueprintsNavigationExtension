// Author: Antonio Sidenko (Tonetfal), May 2024

#pragma once

#include "Engine/DataAsset.h"

#include "SBP_SettingsProfile.generated.h"

USTRUCT(BlueprintType)
struct SLATEBPNAVEXT_API FSBP_SettingsProfile
{
	GENERATED_BODY()

public:
	FSBP_SettingsProfile();

public:
	/** Should the Tab key perform next and previous style navigation. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bTabNavigation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	/** Should we respect keys for navigation. */
	bool bKeyNavigation;

	/** Digital key navigation rules. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bKeyNavigation"))
	TMap<FKey, EUINavigation> KeyEventRules;

	/** Should we respect the analog stick for navigation. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bAnalogNavigation;

	/** Minimum analog value on the horizontal axes should have to perform navigation. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	float AnalogNavigationHorizontalThreshold;

	/** Minimum analog value on the vertical axis should have to perform navigation. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	float AnalogNavigationVerticalThreshold;

	/** Which Axis Key controls horizontal navigation */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	FKey AnalogHorizontalKey;

	/** Which Axis Key controls vertical navigation */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(EditCondition="bAnalogNavigation"))
	FKey AnalogVerticalKey;
};

UCLASS()
class SLATEBPNAVEXT_API USBP_SettingsProfileAsset
	: public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FSBP_SettingsProfile Data;
};
