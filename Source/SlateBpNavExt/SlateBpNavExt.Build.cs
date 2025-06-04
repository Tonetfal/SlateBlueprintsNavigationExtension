// Author: Antonio Sidenko (Tonetfal), May 2024

using UnrealBuildTool;

public class SlateBpNavExt : ModuleRules
{
	public SlateBpNavExt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"DeveloperSettings",
				"Engine",
				"InputCore",
				"Slate",
				"SlateCore",
			}
			);
	}
}
