---
description: Google Test conventions and test coverage requirements
---

## Google Test conventions

- Use `TEST(SuiteName, testName)` — suite name matches the class/module, test name describes the scenario
- Prefer `EXPECT_*` over `ASSERT_*` unless the test cannot continue after failure
- Keep each test focused on one behaviour
- Use `EXPECT_EQ`, `EXPECT_TRUE`, `EXPECT_THAT` (with matchers) as appropriate
- Wrap tests in the library's namespace (e.g. `namespace lib_a { ... }`)

## Coverage requirements

- Happy-path cases for every public function
- Edge cases: empty input, boundary values, zero, null/empty optional
- Error/exception paths (use `EXPECT_THROW` / `EXPECT_NO_THROW`)
- Any invariants or postconditions stated in the Doxygen comments
