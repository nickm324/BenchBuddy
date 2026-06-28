# Storage

Storage owns persistent data boundaries for BenchBuddy.

This area is intended for settings persistence, calibration data, saved inventory records, cache data, and versioned storage formats.

It should provide stable read and write APIs so modules do not depend directly on ESP32 storage implementation details.
