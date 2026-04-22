---
description: SOLID design principles for C++ code
---

## SOLID principles

- **S** (Single responsibility) — each class/function has one clear responsibility
- **O** (Open/closed) — extend behaviour via templates/concepts or virtual interfaces, not `if`/`switch` on types
- **L** (Liskov substitution) — derived types must be substitutable for their base; no `dynamic_cast` to call derived-only methods
- **I** (Interface segregation) — prefer small, focused interfaces over fat abstract base classes with unrelated methods
- **D** (Dependency inversion) — depend on abstractions (concepts / pure virtual interfaces), not concrete types
