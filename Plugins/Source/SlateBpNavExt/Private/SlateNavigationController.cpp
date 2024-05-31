// Author: Antonio Sidenko (Tonetfal), May 2024

#include "SlateNavigationController.h"

#include "Framework/Application/NavigationConfig.h"
#include "SBP_DeveloperSettings.h"
#include "SBP_SettingsProfile.h"

void USlateNavigationController::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	const auto* Settings = GetDefault<USBP_DeveloperSettings>();
	ApplyProfile(Settings->DefaultSettings);
}

void USlateNavigationController::ApplyProfileAsset(const USBP_SettingsProfileAsset* SettingsProfile)
{
	if (IsValid(SettingsProfile))
	{
		ApplyProfile(SettingsProfile->Data);
	}
}

void USlateNavigationController::ApplyProfile(FSBP_SettingsProfile SettingsProfile)
{
	TSharedRef<FNavigationConfig> SlateConfig = FSlateApplication::Get().GetNavigationConfig();
	SlateConfig->bTabNavigation = SettingsProfile.bTabNavigation;
	SlateConfig->bAnalogNavigation = SettingsProfile.bAnalogNavigation;

	SlateConfig->bKeyNavigation = SettingsProfile.bKeyNavigation;
	SlateConfig->KeyEventRules = SettingsProfile.KeyEventRules;

	SlateConfig->AnalogHorizontalKey = SettingsProfile.AnalogHorizontalKey;
	SlateConfig->AnalogVerticalKey = SettingsProfile.AnalogVerticalKey;
	SlateConfig->AnalogNavigationHorizontalThreshold = SettingsProfile.AnalogNavigationHorizontalThreshold;
	SlateConfig->AnalogNavigationVerticalThreshold = SettingsProfile.AnalogNavigationVerticalThreshold;
}

FSBP_SettingsProfile USlateNavigationController::GetActiveProfile() const
{
	FSBP_SettingsProfile SettingsProfile;

	TSharedRef<FNavigationConfig> SlateConfig = FSlateApplication::Get().GetNavigationConfig();
	SettingsProfile.bTabNavigation = SlateConfig->bTabNavigation;
	SettingsProfile.bAnalogNavigation = SlateConfig->bAnalogNavigation;

	SettingsProfile.bKeyNavigation = SlateConfig->bKeyNavigation;
	SettingsProfile.KeyEventRules = SlateConfig->KeyEventRules;

	SettingsProfile.AnalogHorizontalKey = SlateConfig->AnalogHorizontalKey;
	SettingsProfile.AnalogVerticalKey = SlateConfig->AnalogVerticalKey;
	SettingsProfile.AnalogNavigationHorizontalThreshold = SlateConfig->AnalogNavigationHorizontalThreshold;
	SettingsProfile.AnalogNavigationVerticalThreshold = SlateConfig->AnalogNavigationVerticalThreshold;

	return SettingsProfile;
}
