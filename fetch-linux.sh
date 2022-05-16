#!/bin/sh
# script from https://blog.markvincze.com/download-artifacts-from-a-latest-github-release-in-sh-and-powershell/
set -e
LATEST_RELEASE=$(curl -L -s -H 'Accept: application/json' https://github.com/launchdarkly/c-client-sdk/releases/latest)
LATEST_VERSION=$(echo $LATEST_RELEASE | sed -e 's/.*"tag_name":"\([^"]*\)".*/\1/')
ARTIFACT_URL="https://github.com/launchdarkly/c-client-sdk/releases/download/$LATEST_VERSION/linux-gcc-64bit-static.zip"
curl -o linux-gcc-64bit-static.zip -L $ARTIFACT_URL
unzip linux-gcc-64bit-static.zip


# the release only includes C related stuff, so grab the C++ stuff from github raw content
mkdir -p cpp/include/launchdarkly
curl -Ls https://raw.githubusercontent.com/launchdarkly/c-client-sdk/main/cpp/api.cpp > cpp/api.cpp
curl -Ls https://raw.githubusercontent.com/launchdarkly/c-client-sdk/main/cpp/include/launchdarkly/api.hpp > cpp/include/launchdarkly/api.hpp
