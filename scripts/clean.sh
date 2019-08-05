#!/bin/bash

dot="$(pwd)/$(dirname "$0")"
buildDir=$dot/../build
releaseDir=$dot/../release
buildObjDir=$buildDir/obj/
releaseObjDir=$releaseDir/obj/
assetDir=$dot/../assets/

if [ -d "$buildDir" ]; then
  cd $buildDir
  rm *.exe *.pdb *.ilk *.dll
  rm -r $buildObjDir
  if [ -d "$buildDir/assets" ]; then
    rm -r "$buildDir/assets"
  fi
fi

if [ -d "$releaseDir" ]; then
  cd $releaseDir
  rm *.exe *.pdb *.ilk *.dll
  rm -r $releaseObjDir
  if [ -d "$assetDir/assets" ]; then
    rm -r "$assetDir/assets"
  fi
fi
