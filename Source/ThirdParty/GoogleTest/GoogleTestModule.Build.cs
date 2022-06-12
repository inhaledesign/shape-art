using UnrealBuildTool;
using System.IO;

namespace UnrealBuildTool.Rules
{

    public class GoogleTestModule : ModuleRules
    {
        public GoogleTestModule(ReadOnlyTargetRules Target) : base(Target)
        {
            Type = ModuleType.External;
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            string googleTestBasePath = Path.Combine(ModuleDirectory, "googletest-release-1.11.0");
            PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googlemock"));
            PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googlemock", "src"));
            PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googlemock", "include"));
            PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googletest"));
            PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googletest", "src"));
            PublicSystemIncludePaths.Add(Path.Combine(googleTestBasePath, "googletest", "include"));

            if (Target.Platform == UnrealTargetPlatform.Win64) {
                PublicDefinitions.Add("GTEST_OS_WINDOWS=1");
            }
            else if (Target.Platform == UnrealTargetPlatform.Mac) {
                PublicDefinitions.Add("GTEST_OS_MAC=1");
            }
            else if (Target.IsInPlatformGroup(UnrealPlatformGroup.Unix)) {
                PublicDefinitions.Add("GTEST_OS_LINUX=1");
            }

            PublicDefinitions.Add("__GXX_EXPERIMENTAL_CXX0X__=0");
            PublicDefinitions.Add("WIN32_LEAN_AND_MEAN=1");
        }
    }
}