#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/Debug/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/Debug/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/Debug/libQt-Secret.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/Release/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/Release/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/Release/libQt-Secret.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/MinSizeRel/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/MinSizeRel/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/MinSizeRel/libQt-Secret.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src
  /Users/gayuhkautaman/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/RelWithDebInfo/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/RelWithDebInfo/libQt-Secret.1.3.1.dylib /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/Qt-Secret/src/RelWithDebInfo/libQt-Secret.dylib
fi

