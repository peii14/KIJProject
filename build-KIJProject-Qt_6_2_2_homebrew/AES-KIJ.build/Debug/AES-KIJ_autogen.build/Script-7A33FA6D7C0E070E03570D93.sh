#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_autogen /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeFiles/AES-KIJ_autogen.dir/AutogenInfo.json Debug
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_autogen /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeFiles/AES-KIJ_autogen.dir/AutogenInfo.json Release
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_autogen /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeFiles/AES-KIJ_autogen.dir/AutogenInfo.json MinSizeRel
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_autogen /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeFiles/AES-KIJ_autogen.dir/AutogenInfo.json RelWithDebInfo
fi

