.PHONY: clean demoapp

GCC4MBED_DIR=/home/arnavm89/gcc4mbed

#GCC4MBED_TYPE:= Debug
PROJECT         := Homework5
DEVICES         := LPC1768
NO_FLOAT_SCANF  := 1
NO_FLOAT_PRINTF := 0

SRC          := Homework5/Question3
INCDIRS      := inc 
LIBS_PREFIX  :=
LIBS_SUFFIX  :=

OBJCOPY=/home/arnavm89/gcc4mbed/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy


ifdef CUSTOM

CPP=/home/arnavm89/gcc4mbed/gcc-arm-none-eabi/bin/arm-none-eabi-g++
LD=/home/arnavm89/gcc4mbed/gcc-arm-none-eabi/bin/arm-none-eabi-ld
OBJCOPY=/home/arnavm89/gcc4mbed/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy
LPC1768_LSCRIPT = $(GCC4MBED_DIR)/external/mbed/libraries/mbed/targets/cmsis/TARGET_NXP/TARGET_LPC176X/TOOLCHAIN_GCC_ARM/LPC1768.ld

C_FLAGS   := -mcpu=cortex-m3 -mthumb -mthumb-interwork 
ASM_FLAGS := -mcpu=cortex-m3 -mthumb
LD_FLAGS  := -mcpu=cortex-m3 -mthumb

INC=-I/home/arnavm89/gcc4mbed/external/mbed/libraries/mbed/api \
	-I/home/arnavm89/gcc4mbed/external/mbed/libraries/mbed/targets/hal/TARGET_NXP/TARGET_LPC176X/TARGET_MBED_LPC1768 \
	-I/home/arnavm89/gcc4mbed/external/mbed/libraries/mbed/targets/hal/TARGET_NXP/TARGET_LPC176X \
	-I/home/arnavm89/gcc4mbed/external/mbed/libraries/mbed/hal \
	-I/home/arnavm89/gcc4mbed/external/mbed/libraries/mbed/targets/cmsis/TARGET_NXP/TARGET_LPC176X \
	-I/home/arnavm89/gcc4mbed/external/mbed/libraries/mbed/targets/cmsis \
	-I/home/arnavm89/gcc4mbed/mri
	
OBJECTS=main.o \
	startup_LPC17xx.o

vpath %.cpp src
vpath %.s $(GCC4MBED_DIR)/external/mbed/libraries/mbed/targets/cmsis/TARGET_NXP/TARGET_LPC176X/TOOLCHAIN_GCC_ARM

all: output.elf

%.o: %.cpp
	$(CPP) $< $(CFLAGS) $(INC)
	
%.o: %.s
	$(AS) $< $(CFLAGS) $(INC)

output.elf: $(OBJECTS)
#	$(LD) $(OBJECTS) $(LD_FLAGS) -T$(LPC1768_LSCRIPT)
#	$(OBJCOPY) -O HEX output.elf output.hex


clean:
	rm -f *.o
	rm -f output.elf
	rm -f output.hex

else
include $(GCC4MBED_DIR)/build/gcc4mbed.mk

#check:
#	checksum -p cortex-m3 -d LPC1768/$(PROJECT).bin
#	$(OBJCOPY) -I binary -O ihex LPC1768/$(PROJECT).bin LPC1768/$(PROJECT).hex
	
endif