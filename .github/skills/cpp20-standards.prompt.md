---
description: C++20 coding standards and idioms for this project
---

## C++20 standards

- Prefer `concepts` over SFINAE for template constraints
- Use `std::span` instead of raw pointer + size pairs
- Use `std::string_view` for non-owning string parameters
- Use `std::ranges` algorithms over raw loops where idiomatic
- Use structured bindings for destructuring
- Mark functions `[[nodiscard]]` when return values must not be ignored
- Use `constexpr` / `consteval` wherever computation is compile-time eligible
- Prefer `enum class` over unscoped `enum`
- No raw owning pointers — use `std::unique_ptr` / `std::shared_ptr`
- No deprecated C++17-and-earlier patterns where a C++20 alternative exists
- No `using namespace std;` in headers
- No magic numbers — use named `constexpr` constants
