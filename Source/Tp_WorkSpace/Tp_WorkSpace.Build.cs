// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tp_WorkSpace : ModuleRules
{
	public Tp_WorkSpace(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
