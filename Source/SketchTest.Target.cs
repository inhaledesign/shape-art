using UnrealBuildTool;
using System.Collections.Generic;
using System.IO;
 
public class SketchTestTarget : TargetRules
{
    public SketchTestTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Program;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        LinkType = TargetLinkType.Modular;
        LaunchModuleName = "Sketch";

        bIsBuildingConsoleApplication = true;

    }
}
