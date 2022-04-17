namespace UnrealBuildTool.Rules
{
	public class Tests : ModuleRules
	{
		public Tests(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
			PrivatePCHHeaderFile = "Private/Tests.h";
			bEnableExceptions = true;

			string[] publicModules = new string[] { "Core", "CoreUObject" };
			PublicDependencyModuleNames.AddRange(publicModules);
			string[] privateModules = new string[] { "GoogleTest" };
			PrivateDependencyModuleNames.AddRange(privateModules);
		}
	}
}
