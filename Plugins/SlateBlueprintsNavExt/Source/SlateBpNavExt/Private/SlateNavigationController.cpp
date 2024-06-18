// Author: Antonio Sidenko (Tonetfal), May 2024

#include "SlateNavigationController.h"

#include "Framework/Application/NavigationConfig.h"
#include "SlateNavigationExtensionsSettings.h"
#include "SlateNavigationProfile.h"

void USlateNavigationController::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Config = MakeShared<FExtendedNavigationConfig>();
	FSlateApplication::Get().SetNavigationConfig(Config.ToSharedRef());

	const auto* Settings = GetDefault<USlateNavigationExtensionsSettings>();
	ApplyProfile(Settings->DefaultSettings);
}

void USlateNavigationController::ApplyProfileAsset(const USlateNavigationProfileAsset* SettingsProfile)
{
	if (IsValid(SettingsProfile))
	{
		ApplyProfile(SettingsProfile->Data);
	}
}

void USlateNavigationController::ApplyProfile(FSlateNavigationProfile SettingsProfile)
{
	Config->bTabNavigation = SettingsProfile.bTabNavigation;
	Config->bAnalogNavigation = SettingsProfile.bAnalogNavigation;

	Config->bKeyNavigation = SettingsProfile.bKeyNavigation;
	Config->KeyEventRules = SettingsProfile.KeyEventRules;

	Config->AnalogHorizontalKey = SettingsProfile.AnalogHorizontalKey;
	Config->AnalogVerticalKey = SettingsProfile.AnalogVerticalKey;
	Config->AnalogNavigationHorizontalThreshold = SettingsProfile.AnalogNavigationHorizontalThreshold;
	Config->AnalogNavigationVerticalThreshold = SettingsProfile.AnalogNavigationVerticalThreshold;

	Config->KeyActions = SettingsProfile.KeyActions;
}

FSlateNavigationProfile USlateNavigationController::GetActiveProfile() const
{
	FSlateNavigationProfile SettingsProfile;

	SettingsProfile.bTabNavigation = Config->bTabNavigation;
	SettingsProfile.bAnalogNavigation = Config->bAnalogNavigation;

	SettingsProfile.bKeyNavigation = Config->bKeyNavigation;
	SettingsProfile.KeyEventRules = Config->KeyEventRules;

	SettingsProfile.AnalogHorizontalKey = Config->AnalogHorizontalKey;
	SettingsProfile.AnalogVerticalKey = Config->AnalogVerticalKey;
	SettingsProfile.AnalogNavigationHorizontalThreshold = Config->AnalogNavigationHorizontalThreshold;
	SettingsProfile.AnalogNavigationVerticalThreshold = Config->AnalogNavigationVerticalThreshold;

	SettingsProfile.KeyActions = Config->KeyActions;

	return SettingsProfile;
}

EUINavigationAction FExtendedNavigationConfig::GetNavigationActionForKey(const FKey& InKey) const
{
	const auto* FoundAction = KeyActions.Find(InKey);
	return FoundAction ? *FoundAction : EUINavigationAction::Invalid;
}
