# Changelog

All notable changes to this project will be documented in this file.

The format follows a Git Flow based release strategy.

---

# [v1.0.0] - Initial Setup: ST Drivers + DevOps Tools

Release date: 2026-05-11

---

## Overview

This release establishes the initial development infrastructure for the STM32F407G-DISC1 Audio Player project.

The project currently uses STM32CubeMX/CubeIDE generated drivers as the hardware abstraction layer while introducing a professional embedded firmware workflow including:

- Dockerized development environment
- Git Flow branching strategy
- GitHub Actions CI/CD
- Unit testing infrastructure
- Custom Makefile build system

This milestone serves as the foundation for future low-level driver development written from scratch.

---

## Added

### Base Firmware Project
- STM32F407G-DISC1 base firmware project
- STM32CubeMX generated initialization code
- USB Host middleware integration
- FATFS middleware integration

---

### Build System
- Custom Makefile firmware build system
- ARM GNU Toolchain integration
- Standalone firmware compilation outside STM32CubeIDE
- ELF/MAP artifact generation

---

### Docker Environment
- Dockerized embedded firmware development environment
- Ubuntu-based reproducible toolchain container
- ARM GCC toolchain installation
- Ceedling integration for unit testing
- Build reproducibility improvements

---

### Unit Testing
- Ceedling framework integration
- Host-side unit test execution support
- Initial sample unit tests
- Embedded-friendly testing workflow

---

### CI/CD
- GitHub Actions integration
- Automated Docker image build
- Automated firmware compilation
- Automated unit test execution
- Firmware artifact upload support

---

### Documentation
- Initial README documentation
- Docker workflow documentation
- Firmware build instructions
- Unit testing instructions
- GitHub Actions workflow documentation

---

### Version Control & Workflow
- Git Flow branching model
- Feature branch workflow
- Release branch workflow
- Pull request integration workflow
- Protected branch setup

---

## Infrastructure

### Tooling
- Docker
- ARM GNU Toolchain
- Ceedling
- Unity
- CMock
- Clang-format
- GitHub Actions

---

## Planned For Future Releases

- Custom I2S driver implementation
- Custom DMA driver implementation
- Full audio stack from scratch
- Audio buffering architecture
- Safety and fault handling
- MISRA-C compliance
- Doxygen-generated API documentation
- Static analysis integration
- Performance profiling
- Real-time audio optimizations

---

## Release Notes

This release focuses on establishing a professional embedded firmware development environment and scalable project architecture before transitioning into fully custom low-level driver development.

Future milestones will progressively replace STM32CubeMX-generated drivers with custom implementations while maintaining CI/CD, testing, and code quality workflows.