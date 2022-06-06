using UnrealBuildTool;
using System.IO;

namespace UnrealBuildTool.Rules
{

public class Tests : ModuleRules
{
	public Tests(ReadOnlyTargetRules Target) : base(Target)
	{
		bAddDefaultIncludePaths = true;
		bEnableExceptions = true;
		
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "GoogleTestModule" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Sketch" });
	}
}
}
