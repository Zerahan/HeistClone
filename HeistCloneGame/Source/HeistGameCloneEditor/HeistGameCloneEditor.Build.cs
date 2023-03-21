// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class HeistGameCloneEditor : ModuleRules
{
	public HeistGameCloneEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "HeistGameClone" });

		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
	}
}
