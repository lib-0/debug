#!/bin/sh

set -e

cd "$(dirname "$0")"

cmake -DCMAKE_BUILD_TYPE=Release -B builddir_super_release ..
cmake --build builddir_super_release --config Release
cmake --install builddir_super_release --config Release --prefix out_super_release

cmake -DCMAKE_BUILD_TYPE=Debug -B builddir_super_debug ..
cmake --build builddir_super_debug --config Debug
cmake --install builddir_super_debug --config Debug --prefix out_super_debug

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_CONFIG=Release -B builddir_self_release .
cmake --build builddir_self_release --config Release
cmake --install builddir_self_release --config Release --prefix out_self_release

cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_CONFIG=Debug -B builddir_self_debug .
cmake --build builddir_self_debug --config Debug
cmake --install builddir_self_debug --config Debug --prefix out_self_debug
