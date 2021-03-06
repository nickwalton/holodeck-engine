// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Holodeck : ModuleRules
{
	public Holodeck(ReadOnlyTargetRules Target) : base(Target)
	{
        PrivateIncludePaths.AddRange(new [] {
             "Holodeck/Agents/Public",
             "Holodeck/General/Public",
             "Holodeck/Sensors/Public",
             "Holodeck/Utils/Public",
             "Holodeck/HolodeckCore/Public",
             "Holodeck/ClientCommands/Public"
         });

        PublicDependencyModuleNames.AddRange(new [] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "SlateCore", "Slate", "PhysX", "APEX", "JsonUtilities", "RenderCore", "RHI" });

#if PLATFORM_LINUX
        PublicDependencyModuleNames.AddRange(new [] { "rt", "pthread" };
        //TARGET_LINK_LIBRARIES(UHolodeckServer rt pthread)
#endif
	}
}
