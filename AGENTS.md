# Agent Instructions — CppTemplate

A C++20 template project with CMake, Google Test, and automated quality checks. See [README.md](README.md) for project overview.

## Build & Test

```sh
# Configure (always enable tests)
cmake -B build -DBUILD_TESTS=ON

# Build
cmake --build build

# Run all tests
ctest --test-dir build --output-on-failure
```

On macOS, use a CMake preset instead:
```sh
cmake --preset clang        # system clang
cmake --preset clang-llvm   # homebrew LLVM 19
cmake --build build/clang
ctest --test-dir build/clang --output-on-failure
```

After any code change, **always build and run tests** before considering the task done.

## Project Structure

```
main.cpp              # entry point, links libA
lib_a/                # shared library (libA) — model for new libraries
  CMakeLists.txt
  HelloWorldClass.hpp / .cpp
  HelloWorldClass.test.cpp
main.test.cpp         # root-level tests
docs/Doxyfile         # Doxygen config
.github/workflows/    # CI: build, clang-tidy, clang-format, IWYU, Doxygen
```

### Adding a new library

1. Create a subdirectory (e.g., `lib_b/`) modelled after `lib_a/`.
2. Add `add_subdirectory(lib_b)` in the root `CMakeLists.txt`.
3. Link it in the executable: `target_link_libraries(CppTemplate libB)`.

## Conventions

| Convention | Rule |
|---|---|
| C++ standard | C++20 |
| Header guard | `#pragma once` |
| Header extension | `.hpp` |
| Namespace | Match the library directory name (e.g., `lib_a`) |
| Test files | `<SourceFile>.test.cpp`, co-located with source |
| Test prefix | `gtest_discover_tests(target TEST_PREFIX libName)` in `lib_*/CMakeLists.txt` |
| Public API docs | Doxygen `/** ... */` comments on every public function |
| Includes | Only include what you use (IWYU enforced in CI) |

## Code Quality

All checks run in CI on every push/PR. Run locally before submitting:

```sh
# Format (check only)
clang-format --dry-run --Werror *.cpp */*.cpp

# Static analysis (requires compile_commands.json)
cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DBUILD_TESTS=ON
clang-tidy -p build *.cpp */*.cpp

# Documentation
doxygen docs/Doxyfile
```
