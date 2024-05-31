// Author: Antonio Sidenko (Tonetfal), May 2024

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"

#include "SBP_CoreSubsystem.generated.h"

class USBP_SettingsProfileAsset;
struct FSBP_SettingsProfile;

UCLASS()
class USBP_CoreSubsystem final
	: public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//~UGameInstanceSubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	//~End of UGameInstanceSubsystem Interface

public:
	UFUNCTION(BlueprintCallable, meta=(Keywords="settings slate navigation"))
	SLATEBPNAVEXT_API void ApplyProfileAsset(const USBP_SettingsProfileAsset* SettingsProfile);

	UFUNCTION(BlueprintCallable, meta=(Keywords="settings slate navigation"))
	SLATEBPNAVEXT_API void ApplyProfile(FSBP_SettingsProfile SettingsProfile);

	UFUNCTION(BlueprintCallable, meta=(Keywords="settings slate navigation"))
	SLATEBPNAVEXT_API FSBP_SettingsProfile GetActiveProfile() const;
};
