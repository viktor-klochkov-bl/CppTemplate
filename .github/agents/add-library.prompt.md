---
mode: agent
description: Scaffold a new shared C++ library following the lib_a pattern
tools: ['#skill:skills/project-conventions']
---

Add a new C++ shared library named `${input:libName}` to this project.

Follow the existing `lib_a/` pattern exactly:

1. Create `${input:libName}/CMakeLists.txt`:
   - Define a `SOURCES` list
   - Derive `HEADERS` from sources (replace `.cpp` with `.hpp`)
   - Add a `SHARED` library target named `lib${input:libName}` (camelCase e.g. `libB`)
   - Under `if(BUILD_TESTS)`: add a test executable, link the library and `gtest_main`, call `gtest_discover_tests` with `TEST_PREFIX ${input:libName}`

2. Create a starter header `${input:libName}/<ClassName>.hpp` with `#pragma once`, matching namespace, and Doxygen comments.

3. Create the matching implementation `${input:libName}/<ClassName>.cpp`.

4. Create a test file `${input:libName}/<ClassName>.test.cpp` with one passing Google Test.

5. In the root `CMakeLists.txt`:
   - Add `add_subdirectory(${input:libName})`
   - Link the new library to the main executable

After scaffolding, build and run tests:
```sh
cmake -B build -DBUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```
