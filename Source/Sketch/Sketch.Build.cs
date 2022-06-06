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
	}
}
}
