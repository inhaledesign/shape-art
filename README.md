
# Overview
Currently only supports VS Code for Windows, due to dead-end in getting GoogleTest to compile in Linux.

# IDE Setup 

## VS Code

Open ShapeArt in UnrealEditor. Go to `Tools > Refresh` Visual Studio Code Project.

## Tests
1. Install the C++ TestMate extension.
2. In the TestMate extension setting, set "Test: Executables" to `Binaries/Win64/Tests.exe` or `Binaries/Linux/Tests`.
3. Copy the contents of the platform appropriate `code-workspace.example` file into `ShapeArt.code-workspace`.


You'll now have launch configuration called Run Tests. This will build and launch the test executable.