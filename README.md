# BenchBuddy

BenchBuddy is a professional PlatformIO firmware project for an ESP32-based bench companion device.

This repository is currently being prepared with project documentation, licensing, and planning material before application code is added.

## Project Status

Initial project setup is in progress.

Current baseline:

- PlatformIO project
- ESP32 development board target
- Arduino framework
- Project documentation scaffold
- MIT license

## Repository Layout

```text
BenchBuddy/
  docs/
    Architecture.md
  include/
  lib/
  src/
  test/
  platformio.ini
  README.md
  CHANGELOG.md
  ROADMAP.md
  LICENSE
```

## Development Environment

BenchBuddy uses PlatformIO.

Configured environment:

- Platform: Espressif 32
- Board: ESP32 Dev Module
- Framework: Arduino

Typical PlatformIO commands:

```sh
pio run
pio test
pio run --target upload
```

## Documentation

- [Architecture](docs/Architecture.md)
- [Roadmap](ROADMAP.md)
- [Changelog](CHANGELOG.md)

## License

BenchBuddy is licensed under the MIT License. See [LICENSE](LICENSE).
