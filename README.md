# STM32F407G-DISC1 Audio Player Project

## Overview
This project started with STM32CubeMX-generated drivers for the STM32F407G-DISC1 board and basic audio playback using the CS43L22 codec.  
The main goal is to progressively replace auto-generated drivers with **custom low-level implementations written from scratch**, while building a professional embedded development workflow.

## Roadmap
- Base project with CubeMX drivers ✅
- Audio codec integration (CS43L22) ✅
- Custom I2S driver (in progress)
- Custom DMA driver (planned)
- Full audio stack from scratch (planned)
- GitHub Actions CI/CD (planned)
- Custom Makefile build system (planned)
- Dockerized build environment (planned)
- Unit testing framework (planned)
- Doxygen documentation (planned)
- Safety functions and fault handling (planned)
- MISRA C compliance (planned)

## Hardware
- STM32F407G-DISC1 development board
- CS43L22 audio codec (on-board)
- External storage for WAV files

## License
- Original STM32CubeMX drivers: SLA0044 (STMicroelectronics)
- Custom drivers and adaptations: MIT License

## Demo
Future updates will include videos and documentation showing audio playback, buffer management, and integration of custom drivers.
