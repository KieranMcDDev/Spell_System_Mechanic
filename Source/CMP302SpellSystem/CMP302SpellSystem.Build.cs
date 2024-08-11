// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CMP302SpellSystem : ModuleRules
{
	public CMP302SpellSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
