#!/bin/bash

[[ ! -d .git ]] && git init

drogon_exist=$(git submodule status | grep drogon &>/dev/null; echo $?)
gtest_exist=$(git submodule status | grep googletest &>/dev/null; echo $?)

echo "Drogon status " ${drogon_exist}
echo "GoogleTest status " ${gtest_exist}

if [[ ${drogon_exist} == 1 ]]; then
    git submodule add https://github.com/an-tao/drogon.git ./ext/drogon
fi

if [[ ${gtest_exist} == 1 ]]; then
    git submodule add https://github.com/google/googletest.git ./ext/googletest
fi

if [[ i${drogon_exist} == 1 || ${gtest_exist} == 1 ]]; then
    git submodule update --init --recursive
fi

