// Author: Antonio Sidenko (Tonetfal), May 2024

#pragma once

#include "Framework/Application/NavigationConfig.h"
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
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
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

private:
	TSharedPtr<class FExtendedNavigationConfig> Config = nullptr;
};

class FExtendedNavigationConfig
	: public FNavigationConfig
{
public:
	//~FNavigationConfig Interface
	virtual EUINavigationAction GetNavigationActionForKey(const FKey& InKey) const override;
	//~End of FNavigationConfig Interface

public:
	TMap<FKey, EUINavigationAction> KeyActions;
};
