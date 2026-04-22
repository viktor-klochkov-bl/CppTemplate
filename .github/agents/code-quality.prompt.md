---
mode: agent
description: Run clang-format and clang-tidy, fix violations, verify build
---

Run all code quality checks and fix any violations found.

## Steps

1. **Generate compile commands**:
   ```sh
   cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DBUILD_TESTS=ON
   cmake --build build
   ```

2. **clang-format** — check then auto-fix:
   ```sh
   clang-format --dry-run --Werror *.cpp */*.cpp */*.hpp
   clang-format -i *.cpp */*.cpp */*.hpp
   ```

3. **clang-tidy** — report then apply fixes:
   ```sh
   clang-tidy -p build *.cpp */*.cpp
   clang-tidy -p build --fix *.cpp */*.cpp
   ```

4. **Verify** — build and test after fixes:
   ```sh
   cmake --build build
   ctest --test-dir build --output-on-failure
   ```

Report a summary of changes. List any clang-tidy issues that cannot be auto-fixed with file, line, and recommended fix.
