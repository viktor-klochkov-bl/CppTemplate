---
mode: agent
description: Build the project and run all tests, reporting a clear pass/fail summary
---

Build the project and run the full test suite.

## Steps

1. **Configure**:
   ```sh
   cmake -B build -DBUILD_TESTS=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
   ```

2. **Build**:
   ```sh
   cmake --build build
   ```

3. **Run all tests**:
   ```sh
   ctest --test-dir build --output-on-failure
   ```

## Reporting

### Build
- ✅ Build succeeded  **or**  🔴 Build failed — paste compiler errors

### Test results
| Suite | Passed | Failed | Skipped |
|---|---|---|---|

List every **failing test** with:
- Full test name
- Failure message / assertion that fired
- File and line number

### Next steps
If any tests fail or the build is broken, diagnose the root cause and propose a concrete fix. Do not apply fixes automatically — wait for confirmation unless called from the orchestrator.
