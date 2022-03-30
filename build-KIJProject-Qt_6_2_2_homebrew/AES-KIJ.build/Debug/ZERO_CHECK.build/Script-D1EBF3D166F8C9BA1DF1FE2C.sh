#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  make -f /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  make -f /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  make -f /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew
  make -f /Users/gayuhkautaman/Documents/code/cpp/KIJProject/build-KIJProject-Qt_6_2_2_homebrew/CMakeScripts/ReRunCMake.make
fi

