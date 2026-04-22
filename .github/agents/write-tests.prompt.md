---
mode: agent
description: Write Google Tests for existing C++ code
tools: ['#skill:skills/gtest-conventions', '#skill:skills/project-conventions']
---

Write Google Tests for: ${input:target}

Apply the Google Test conventions and project conventions from the attached skills.

## Steps

1. **Locate the source** — find the `.hpp` and `.cpp` files for the target code.
2. **Create or update the test file** `<SourceFile>.test.cpp` co-located with the source.
3. **Achieve full coverage** per the test coverage requirements in the gtest-conventions skill.
4. **Wire up if new** — if the test file is new, ensure `lib_*/CMakeLists.txt` lists it under `TEST_SOURCES`.
5. **Build and run tests**:
   ```sh
   cmake -B build -DBUILD_TESTS=ON
   cmake --build build
   ctest --test-dir build --output-on-failure
   ```
6. Report the test results and list every test case added.
