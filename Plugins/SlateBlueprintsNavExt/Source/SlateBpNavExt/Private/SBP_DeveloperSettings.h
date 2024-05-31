// Author: Antonio Sidenko (Tonetfal), May 2024

#pragma once

#include "Engine/DeveloperSettings.h"
#include "SBP_SettingsProfile.h"

#include "SBP_DeveloperSettings.generated.h"

UCLASS(Config="Engine", DefaultConfig, DisplayName="Slate & Blueprint Navigation Extension")
class USBP_DeveloperSettings
	: public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/** Default settings applied to the game when it starts. */
	UPROPERTY(Config, EditDefaultsOnly)
	FSBP_SettingsProfile DefaultSettings;
};
