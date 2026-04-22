---
description: Project-specific conventions for CppTemplate (namespaces, headers, tests, docs)
---

## Project conventions

See [AGENTS.md](../../../AGENTS.md) for full details.

- Place code in the appropriate `lib_*/` subdirectory; create a new library if needed
- Header extension: `.hpp` with `#pragma once`
- Namespace: match the library directory name (e.g. `lib_a`)
- Only include what you use (IWYU) — never umbrella-include
- Test files: `<SourceFile>.test.cpp`, co-located with source
- Test prefix: `gtest_discover_tests(target TEST_PREFIX libName)` in each `lib_*/CMakeLists.txt`
- Public API docs: Doxygen `/** ... */` with `@brief`, `@param`, `@return` on every public function and class
- Functions should be short and do one thing (< ~30 lines guideline)
- Error handling must be explicit — no silent swallowing of exceptions
