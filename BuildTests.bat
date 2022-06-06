@echo off
setlocal enableDelayedExpansion

set UEDir=..\..\UE5
set buildScript=!UEDir!\Engine\Build\BatchFiles\Build.bat
set projectDir=%~dp0
set projectFile=ShapeArt.uproject
set testTarget=Tests
set build="!buildScript!" "!testTarget!" Development Win64 "!projectDir!!projectFile!" -waitmutex

call !build!