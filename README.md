
# Overview
Currently only supports VS Code for Windows, due to dead-end in getting GoogleTest to compile in Linux.

# IDE Setup 

## VS Code

Open ShapeArt in UnrealEditor. Go to Tools > Refresh Visual Studio Code Project. Note that this wil overwrite any changes you have made to existing VS Code configuration files in the project.

## Tests
1. Install the GoogleTestAdapter extension
2. Add these tasks to .vscode/tasks.json:

```
{
    "label": "SketchTest Build",
    "group": "build",
    "command": "Engine\\Build\\BatchFiles\\Build.bat",
    "args": [
        "SketchTest",
        "Development",
        "Win64",
        "${workspaceFolder}\\ShapeArt.uproject",
        "-waitmutex"
    ]
    ,
    "options": {
        "cwd": "C:\\Path\\To\\UE5" // Make sure you change this!
    },
    "problemMatcher": "$msCompile",
    "type": "shell"
},
{
    "label": "SketchTest Clean",
    "group": "build",
    "command": "Engine\\Build\\BatchFiles\\Clean.bat",
    "args": [
        "SketchTest",
        "Development",
        "Win64",
        "${workspaceFolder}\\ShapeArt.uproject",
        "-waitmutex"
    ],
    "problemMatcher": "$msCompile",
    "type": "shell",
    "options": {
        "cwd": "C:\\Path\\To\\UE5" // Make sure you change this!
    }
}
```

3. Add this launch config to .vscode/launch.json:

```
{
    "name": "GoogleTest Sketch",
    "request": "launch",
    "program": "${workspaceFolder}\\Binaries\\Win64\\SketchTest.exe",
    "preLaunchTask": "SketchTest Build",
    "args": [],
    "console": "integratedTerminal",
    "type": "cppvsdbg",
    "cwd": "C:\\Path\\To\\UE5" // Make sure you change this!
}
```

4. Open the GoogleTest tool, click the "Switch Test Configuration" button, and select "GoogleTest Sketch". This should run the tests, and also generate a .vscode/settings.json file. Add the following settings to that file:

```
"gtest-adapter.debugConfig": "GoogleTest Sketch",
// below are recommended settings
"gtest-adapter.showRunOutput": false,
"gtest-adapter.supportLocation": true,
"gtest-adapter.refreshAfterBuild": true,
"gtest-adapter.runAfterBuild": true,
"gtest-adapter.showCodeLens": true,
"gtest-adapter.clearRunOutput": true
```

5. Update includedir in CodeLens to include GoogleTest
