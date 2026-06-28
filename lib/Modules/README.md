# Modules

Modules contains BenchBuddy's user-facing feature areas.

Each module should own its local screens, feature state, labels, and interactions while depending on shared services from Core, Display, Navigation, Storage, Touch, and Theme.

Modules should avoid direct hardware access unless explicitly routed through a shared abstraction.
