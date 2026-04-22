---
description: Code review checklist for C++20, SOLID, conventions, and general quality
---

## Review checklist

For every issue found, output:
- **File** and **line**
- **Severity**: 🔴 must-fix / 🟡 should-fix / 🔵 suggestion
- **Explanation** and a concrete corrected snippet

### C++20 correctness
- [ ] Uses `#pragma once` (not include guards)
- [ ] `std::string_view` / `std::span` preferred over raw pointer + size pairs
- [ ] Owning pointers use `std::unique_ptr` or `std::shared_ptr`; raw `new`/`delete` absent
- [ ] `[[nodiscard]]` on functions whose return value must not be ignored
- [ ] `constexpr` / `consteval` used where computation is compile-time eligible
- [ ] `enum class` instead of unscoped `enum`
- [ ] Range-based algorithms (`std::ranges::`) preferred over raw loops where idiomatic
- [ ] No deprecated C++17-and-earlier patterns where a C++20 alternative exists

### SOLID principles
- [ ] **S**ingle responsibility — each class/function does one thing
- [ ] **O**pen/closed — extended via templates/concepts or virtual interfaces
- [ ] **L**iskov substitution — overrides preserve base-class contracts
- [ ] **I**nterface segregation — no "fat" abstract base with unrelated methods
- [ ] **D**ependency inversion — high-level code depends on abstractions

### Project conventions
- [ ] Namespace matches library directory name
- [ ] Header uses `.hpp` extension
- [ ] IWYU — every `#include` is actually used; nothing missing
- [ ] Public functions have Doxygen `/** @brief ... @param ... @return ... */`
- [ ] Test file exists co-located with source (`<File>.test.cpp`)

### General quality
- [ ] No magic numbers — named `constexpr` constants used
- [ ] Functions are short (< ~30 lines guideline)
- [ ] Error handling is explicit; no silent swallowing
- [ ] No `using namespace std;` in headers

## Output format

Summarise in a table:

| Severity | File | Line | Issue | Suggested fix |
|---|---|---|---|---|

Then detailed explanations with corrected code snippets for every 🔴 and 🟡 item.
If no issues in a category, state "✅ No issues".
