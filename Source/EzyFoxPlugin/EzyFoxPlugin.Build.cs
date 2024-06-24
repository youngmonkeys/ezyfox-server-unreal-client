// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class EzyFoxPlugin : ModuleRules
{
	public EzyFoxPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
		
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
			PublicDefinitions.Add("USE_WINSOCK_2");
        }
		PublicDefinitions.Add("EZY_DLL_EXPORT=EZYFOXPLUGIN_API");

        PrivateIncludePaths.Add(ModuleDirectory);
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "src"));

        PublicIncludePaths.Add(ModuleDirectory);
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "src"));
    }
}
