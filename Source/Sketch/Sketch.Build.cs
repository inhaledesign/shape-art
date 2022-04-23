using UnrealBuildTool;
using System.IO;

namespace UnrealBuildTool.Rules
{

public class Sketch : ModuleRules
{
	public Sketch(ReadOnlyTargetRules Target) : base(Target)
	{
		bAddDefaultIncludePaths = true;
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core" });
		PrivateDependencyModuleNames.AddRange(new string[] { "GoogleTest" });

		string googleTestBasePath = Path.Combine("$(ProjectDir)", "Source", "ThirdParty", "GoogleTest", "googletest-release-1.11.0");

		PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googlemock"));
		PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googlemock", "src"));
		PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googlemock", "include"));
		PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googletest"));
		PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googletest", "src"));
		PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googletest", "include"));
	}
}
}
