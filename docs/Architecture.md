# BenchBuddy Architecture

BenchBuddy is organized as a PlatformIO firmware project targeting an ESP32 development board with the Arduino framework.

This document describes the intended architecture before application code is introduced.

## Goals

- Keep hardware-specific code isolated from application behavior.
- Keep device state explicit and easy to test.
- Make diagnostics available early in development.
- Support incremental firmware growth without forcing large rewrites.

## Platform Baseline

- Build system: PlatformIO
- Platform: Espressif 32
- Board: ESP32 Dev Module
- Framework: Arduino

## Proposed Firmware Layers

```text
Application
  Coordinates device behavior and user-facing workflows.

Domain Logic
  Owns state transitions, calculations, validation, and policy.

Services
  Provides logging, configuration, timing, persistence, and communication.

Hardware Abstraction
  Wraps GPIO, sensors, displays, buttons, encoders, relays, or other peripherals.

Platform
  Arduino and ESP32 framework APIs.
```

## Directory Responsibilities

```text
src/
  Firmware entry point and application composition.

include/
  Public project headers shared across firmware modules.

lib/
  Reusable internal libraries or vendored PlatformIO libraries.

test/
  PlatformIO tests for logic that can be validated off-device or on-device.

docs/
  Architecture notes, design decisions, and project documentation.
```

## Design Principles

- Prefer small modules with clear ownership.
- Avoid mixing hardware access directly into business logic.
- Keep timing-sensitive code explicit and documented.
- Treat configuration, calibration, and persisted state as versioned data.
- Add tests around deterministic logic before adding complex integrations.

## Planned Subsystems

- Device state model
- Hardware input handling
- Hardware output control
- Configuration storage
- Diagnostics and logging
- Fault detection and recovery
- Test harnesses for deterministic logic

## Open Decisions

- Final hardware bill of materials.
- Required sensors, controls, displays, or communication interfaces.
- Configuration and calibration storage format.
- Logging format and verbosity controls.
- Release versioning policy.
