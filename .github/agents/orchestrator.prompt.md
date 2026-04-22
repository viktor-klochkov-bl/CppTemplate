---
mode: agent
description: Full development cycle — write code, review, write tests, run tests, fix issues
tools: ['#agent:agents/write-cpp-code', '#agent:agents/review-code', '#agent:agents/write-tests', '#agent:agents/run-tests']
---

Complete the following development task end-to-end: ${input:task}

Work through each phase below in order. Do not skip a phase.

---

## Phase 1 — Write code

Use the **write-cpp-code** agent to implement the task.
Build after writing to confirm zero compiler errors before proceeding.

---

## Phase 2 — Review code

Use the **review-code** agent on everything written in Phase 1.
Apply all 🔴 must-fix items immediately.
Apply 🟡 should-fix items unless they significantly change scope.
List 🔵 suggestions in the final report but do not apply them.

Rebuild after fixes:
```sh
cmake --build build
```

---

## Phase 3 — Write tests

Use the **write-tests** agent for all code produced in Phase 1.
Cover happy paths, edge cases, and error paths.

---

## Phase 4 — Run tests

Use the **run-tests** agent to build and run the full test suite.

---

## Phase 5 — Fix issues (repeat until green)

If Phase 4 reports failures:

1. Diagnose each failing test.
2. Determine whether the fault is in the **implementation** or the **test**:
   - Implementation bug → fix the source code, not the test
   - Wrong test expectation → fix the test assertion with justification
3. Apply the fix and return to Phase 4.
4. Repeat until `ctest` reports 100% pass rate.

**Stop condition**: all tests pass and the build is clean.

---

## Final report

| Phase | Outcome | Notes |
|---|---|---|
| Write code | ✅ / 🔴 | files created/modified |
| Review | ✅ / 🟡 | issues found & fixed |
| Write tests | ✅ | test cases added |
| Run tests | ✅ | pass/fail counts |
| Fix issues | ✅ / N/A | iterations needed |

List every file created or modified.
