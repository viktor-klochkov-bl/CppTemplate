---
mode: agent
description: Write C++ code following project conventions (C++20, SOLID, IWYU, Doxygen)
tools: ['#skill:skills/cpp20-standards', '#skill:skills/solid-principles', '#skill:skills/project-conventions']
---

Implement the following in C++: ${input:task}

Apply all rules from the attached skills: C++20 standards, SOLID principles, and project conventions.

## After writing code

1. If a new library was created, wire it up following [AGENTS.md](../../AGENTS.md#adding-a-new-library)
2. Build to verify it compiles:
   ```sh
   cmake -B build -DBUILD_TESTS=ON
   cmake --build build
   ```
3. Report any compile errors and fix them before finishing.
