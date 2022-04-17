using UnrealBuildTool;
using System.Collections.Generic;
using System.IO;
 
public class TestsTarget : TargetRules
{
    public TestsTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Program;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        LinkType = TargetLinkType.Modular;
        LaunchModuleName = "Tests";
 
        bIsBuildingConsoleApplication = true;
    }
}
