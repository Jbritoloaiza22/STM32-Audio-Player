# STM32F407G-DISC1 Audio Player Project

## Overview

This project started with STM32CubeMX-generated drivers for the STM32F407G-DISC1 board and basic audio playback using the CS43L22 codec.

The main goal is to progressively replace auto-generated drivers with custom low-level implementations written from scratch, while building a professional embedded development workflow.

The project also focuses on:
- Embedded software architecture
- CI/CD integration
- Unit testing
- Dockerized reproducible builds
- Code quality and documentation
- Safety-oriented firmware design

---

## Roadmap

- Base project with CubeMX drivers ✅
- Audio codec integration (CS43L22)
- Custom I2S driver (in progress)
- Custom DMA driver (planned)
- Full audio stack from scratch (planned)
- GitHub Actions CI/CD ✅
- Custom Makefile build system ✅
- Dockerized build environment ✅
- Unit testing framework with Ceedling/Unity ✅
- Doxygen documentation (planned)
- Safety functions and fault handling (planned)
- MISRA C compliance (planned)

---

## Hardware

- STM32F407G-DISC1 development board
- CS43L22 audio codec (on-board)
- USB storage device for WAV playback

---

## Project Structure

```text
audioexample/
│
├── Core/
├── Drivers/
├── FATFS/
├── Middlewares/
├── USB_HOST/
├── Debug/
├── docker/
├── unit_test/
│   ├── src/
│   ├── test/
│   ├── vendor/
│   └── project.yml
│
├── .github/
│   └── workflows/
│       └── build.yml
│
└── README.md
```

---

# Docker Build Environment

This project uses Docker to provide a reproducible embedded firmware development environment.

The Docker image includes:
- ARM GNU Toolchain
- Ceedling
- Unity
- CMock
- Clang-format
- GCC build tools
- CMake and Ninja

---

## Build Docker Image

From the project root:

```bash
docker build -t stm32-build -f docker/Dockerfile .
```

---

## Run Docker Container

### Windows CMD

```bash
docker run --rm -it -v "%cd%:/workspace" stm32-build
```

### Git Bash

```bash
docker run --rm -it -v "$(pwd):/workspace" stm32-build
```

---

# Firmware Build

Inside the container:

```bash
cd /workspace/Debug
make clean
make all
```

Generated output:

```text
STM32AudioPlayer.elf
STM32AudioPlayer.map
```

---

# Unit Testing

This project uses:
- Ceedling
- Unity
- CMock

for host-based unit testing.

The unit test environment allows testing embedded C logic on the host machine without requiring hardware.

---

## Unit Test Structure

```text
unit_test/
│
├── src/
│   ├── math.c
│   └── math.h
│
├── test/
│   └── test_math.c
│
├── vendor/
│
└── project.yml
```

---

## Run Unit Tests

### 1. Start Docker Container

#### Windows CMD

```bash
docker run --rm -it -v "%cd%:/workspace" stm32-build
```

#### Git Bash

```bash
docker run --rm -it -v "$(pwd):/workspace" stm32-build
```

---

### 2. Go to Unit Test Directory

```bash
cd /workspace/unit_test
```

---

### 3. Run All Tests

```bash
ceedling test:all
```

Example output:

```text
TESTED:  2
PASSED:  2
FAILED:  0
IGNORED: 0
```

---

# GitHub Actions CI/CD

GitHub Actions automatically:
- Builds Docker image
- Compiles firmware
- Runs unit tests

Workflow location:

```text
.github/workflows/build.yml
```

---

## Example GitHub Actions Workflow

```yaml
name: STM32 Build

on:
  push:
    branches:
      - main
      - dev
      - feature/**

  pull_request:
    branches:
      - main
      - dev

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout repository
        uses: actions/checkout@v4

      - name: Build Docker image
        run: docker build -t stm32-build -f docker/Dockerfile .

      - name: Build firmware
        run: |
          docker run --rm \
            -v ${{ github.workspace }}:/workspace \
            stm32-build \
            bash -c '
              cd /workspace/Debug
              make clean
              make all
            '

      - name: Run unit tests
        run: |
          docker run --rm \
            -v ${{ github.workspace }}:/workspace \
            stm32-build \
            bash -c '
              cd /workspace/unit_test
              ceedling test:all
            '
```

---

# Development Goals

This project aims to demonstrate:
- Embedded firmware architecture
- Low-level peripheral driver development
- Real-time audio streaming
- Embedded CI/CD pipelines
- Professional Git workflow
- Unit testing in embedded systems
- Reproducible builds with Docker
- Code quality practices for production firmware

---

# License

- Original STM32CubeMX drivers: SLA0044 (STMicroelectronics)
- Custom drivers and adaptations: MIT License

---

# Demo

Future updates will include:
- Audio playback demos
- DMA streaming demonstrations
- Buffer management visualization
- Custom peripheral driver bring-up
- CI/CD demonstrations
- Unit testing examples
- Audio pipeline architecture documentation
- Performance measurements and profiling