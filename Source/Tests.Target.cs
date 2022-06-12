using UnrealBuildTool;
 
public class TestsTarget : TargetRules
{
    public TestsTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Program;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        LinkType = TargetLinkType.Modular;
        LaunchModuleName = "Tests";
        bIsBuildingConsoleApplication = true;
        bCompileAgainstEngine = false;
        bCompileAgainstCoreUObject = false;
        bCompileAgainstApplicationCore	= false;

        // Keeps macro definitions in Tests.Build.cs from throwing errors.
        // Note: The space at the beginning of the string is necessary, otherwise the first argument is ignored.
        if(Platform == UnrealTargetPlatform.Linux) {
            AdditionalCompilerArguments=" -Wno-error=macro-redefined -Wno-error=undef";
        }
    }
}
