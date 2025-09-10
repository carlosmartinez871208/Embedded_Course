# Build Complex Device Drivers
SRC_DIR := src
OBJ_DIR  = ../../../build/obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES =\
-Iinc\
-I../../../inc/generic/\
-I../../../inc/autosar/\

# Microcontroller Processor Architecture:
MACH = cortex-m4
#Flags
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -g
# Compiler variables:
CC = arm-none-eabi-gcc

all: $(OBJECTS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo "Building CDD...!"
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $< -o $@

.PHONY: all
