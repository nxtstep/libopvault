#!/usr/bin/env bash

set -eo pipefail

pushd "$(dirname "$0")"

#rm -Rf build
mkdir -p build

conan install . --output-folder=build --build=missing --profile:host
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .

popd
