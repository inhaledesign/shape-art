@echo off
setlocal enableDelayedExpansion

set UEDir=C:\Users\bob\Documents\UE5
set buildScript=!UEDir!\Engine\Build\BatchFiles\Build.bat
set projectDir=%~dp0
set projectFile=ShapeArt.uproject
set build="!buildScript!" SketchTest Development Win64 "!projectDir!!projectFile!" -waitmutex

call !build!