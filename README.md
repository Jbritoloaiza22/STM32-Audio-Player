# STM32F407 Audio Player Project

## Overview
This project started with STM32CubeMX-generated drivers for STM32F407 and basic audio playback using the CS43L22 codec.  
The purpose is to progressively replace auto-generated drivers with **custom low-level implementations written from scratch**, gaining full control over I2S, DMA, and audio streaming.

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
- STM32F407 custom board
- CS43L22 audio codec
- External storage for WAV files

## License
- Original STM32CubeMX drivers: SLA0044 (STMicroelectronics)
- Custom drivers and adaptations: MIT License

## Demo
Future updates will include videos and documentation showing audio playback, buffer management, and integration of custom drivers.
