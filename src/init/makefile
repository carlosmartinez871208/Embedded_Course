# Buils initialization system
# Microcontroller Processor Architecture:
MACH = cortex-m4
#Flags
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -g
# Compiler variables:
CC = arm-none-eabi-gcc

OBJECTS = ../../build/obj

INCLUDES =\
-Iinc\
-I../../inc/generic/\
-I../../inc/autosar/\

MAIN_PATH = main
STUP_PATH = startup

.PHONY: all

all:
	@echo "Building System initilization code...!"
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $(MAIN_PATH)/main.c -o $(OBJECTS)/main.o
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $(STUP_PATH)/Stm32f429zi_Startup.c -o $(OBJECTS)/Stm32f429zi_Startup.o
