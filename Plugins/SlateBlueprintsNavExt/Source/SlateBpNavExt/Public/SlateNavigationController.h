// Author: Antonio Sidenko (Tonetfal), May 2024

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"

#include "SlateNavigationController.generated.h"

class USlateNavigationProfileAsset;
struct FSlateNavigationProfile;

UCLASS(BlueprintType, MinimalAPI)
class USlateNavigationController final
	: public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//~UGameInstanceSubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	//~End of UGameInstanceSubsystem Interface

public:
	UFUNCTION(BlueprintCallable, Category="Slate & Blueprint Navigation Extensions",
		meta=(Keywords="settings slate navigation"))
	SLATEBPNAVEXT_API void ApplyProfileAsset(const USlateNavigationProfileAsset* SettingsProfile);

	UFUNCTION(BlueprintCallable, Category="Slate & Blueprint Navigation Extensions",
		meta=(Keywords="settings slate navigation"))
	SLATEBPNAVEXT_API void ApplyProfile(FSlateNavigationProfile SettingsProfile);

	UFUNCTION(BlueprintPure, Category="Slate & Blueprint Navigation Extensions",
		meta=(Keywords="settings slate navigation"))
	SLATEBPNAVEXT_API FSlateNavigationProfile GetActiveProfile() const;
};
