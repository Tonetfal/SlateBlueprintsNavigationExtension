// Author: Antonio Sidenko (Tonetfal), May 2024

#pragma once

#include "Engine/DeveloperSettings.h"
#include "SlateNavigationProfile.h"

#include "SlateNavigationExtensionsSettings.generated.h"

UCLASS(Config="Engine", DefaultConfig, DisplayName="Slate & Blueprint Navigation Extension")
class USlateNavigationExtensionsSettings
	: public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/** Default settings applied to the game when it starts. */
	UPROPERTY(Config, EditDefaultsOnly)
	FSlateNavigationProfile DefaultSettings;
};
