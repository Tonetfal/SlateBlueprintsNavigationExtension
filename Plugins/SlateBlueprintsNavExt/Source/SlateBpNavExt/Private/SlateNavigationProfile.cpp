// Author: Antonio Sidenko (Tonetfal), May 2024

#include "SlateNavigationProfile.h"

FSlateNavigationProfile::FSlateNavigationProfile()
	: bTabNavigation(true)
	, bKeyNavigation(true)
	, bAnalogNavigation(true)
	, AnalogNavigationHorizontalThreshold(0.50f)
	, AnalogNavigationVerticalThreshold(0.50f)
{
	AnalogHorizontalKey = EKeys::Gamepad_LeftX;
	AnalogVerticalKey = EKeys::Gamepad_LeftY;

	KeyEventRules.Emplace(EKeys::Left, EUINavigation::Left);
	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Left, EUINavigation::Left);

	KeyEventRules.Emplace(EKeys::Right, EUINavigation::Right);
	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Right, EUINavigation::Right);

	KeyEventRules.Emplace(EKeys::Up, EUINavigation::Up);
	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Up, EUINavigation::Up);

	KeyEventRules.Emplace(EKeys::Down, EUINavigation::Down);
	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Down, EUINavigation::Down);
}
