#! /bin/bash

UEDir=../../UE5
buildScript=$UEDir/Engine/Build/BatchFiles/Linux/Build.sh
projectFile=ShapeArt.uproject
testTarget=Tests
build="$buildScript $testTarget Development Linux $PWD/$projectFile -waitmutex"

echo $build
$build
