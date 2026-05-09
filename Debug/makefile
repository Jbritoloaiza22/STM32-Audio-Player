#/**
# * @file    project firmware
# * @brief   Audio  firmware for STM32F407
# *
# * @copyright
# * Copyright (c) 2026 Jesus Daniel Britoloaiza
# * All rights reserved.
#*/
# ================= TOOLCHAIN =================
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# ================= PROJECT =================
TARGET = STM32AudioPlayer
MCU = cortex-m0plus

LINKER_SCRIPT = ../STM32F407VGTX_FLASH.ld

# ================= FLAGS =================
CFLAGS = -mcpu=$(MCU) -mthumb -std=gnu11 \
         -O0 -g3 \
         -ffunction-sections -fdata-sections \
         -Wall -Wextra -fno-common \
         -DUSE_HAL_DRIVER -DSTM32F407xx \
         -mfloat-abi=soft

LDFLAGS = -mcpu=$(MCU) -mthumb \
          -T$(LINKER_SCRIPT) \
          -Wl,--gc-sections \
          -Wl,-Map=$(TARGET).map \
          --specs=nano.specs \
          --specs=nosys.specs \
          -mfloat-abi=soft

# ================= INCLUDE PATHS =================
INCLUDES = \
-I../Core/Inc \
-I../Drivers/CMSIS/Include \
-I../Drivers/CMSIS/Device/ST/STM32F4xx/Include \
-I../Drivers/STM32F4xx_HAL_Driver/Inc \
-I../Middlewares \
-I../Middlewares/Third_Party/FatFs/src \
-I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc \
-I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc \
-I../FATFS/App \
-I../FATFS/Target \
-I../USB_HOST/App \
-I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc \
-I../USB_HOST/Target

# ================= SOURCES =================
C_SRCS := $(shell find ../Core/Src -type f -name "*.c")
C_SRCS += $(shell find ../Drivers/STM32F4xx_HAL_Driver/Src -type f -name "*.c")
C_SRCS += $(shell find ../FATFS/App -type f -name "*.c")
C_SRCS += $(shell find ../FATFS/Target -type f -name "*.c")
C_SRCS += $(shell find ../USB_HOST/App -type f -name "*.c")
C_SRCS += $(shell find ../USB_HOST/Target -type f -name "*.c")
C_SRCS += $(shell find ../Middlewares/Third_Party/FatFs/src -type f -name "*.c")
C_SRCS += $(shell find ../Middlewares/ST/STM32_USB_Host_Library/Core/Src -type f -name "*.c")
C_SRCS += $(shell find ../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src -type f -name "*.c")

S_SRCS := $(shell find ../Core/Startup -type f \( -name "*.s" -o -name "*.S" \))

# remove duplicates sources
OBJS := $(sort $(C_SRCS:.c=.o) $(S_SRCS:.s=.o))

# ================= BUILD =================
all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	@echo "Linking firmware..."
	$(CC) $(OBJS) $(LDFLAGS) -o $@
	$(SIZE) $@

# ================= COMPILE =================
%.o: %.c
	@echo "CC $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.s
	@echo "ASM $<"
	$(CC) -x assembler-with-cpp $(CFLAGS) -c $< -o $@

# ================= OUTPUT =================
bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $(TARGET).bin

hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $(TARGET).hex

# ================= CLEAN =================
clean:
	rm -rf $(OBJS) \
	       $(TARGET).elf \
	       $(TARGET).bin \
	       $(TARGET).hex \
	       $(TARGET).map

.PHONY: all clean bin hex