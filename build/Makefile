#########################################################################################################
# $File: makefile
# $Revision: Version 1.0 $
# $Author: Carlos Martinez $
# $Date: 2025-03-23 $
#
# Descritpion:
#              This file is used to build the entire project
#########################################################################################################
# All includes are ound here:
-include includes.mk

# Project name:
# if no NAME argument, it will take the main project folder name as project name.
NAME =
ifeq ($(NAME),)
 PROJECT = $(notdir $(abspath ..))
else
 PROJECT = $(NAME)
endif

# Folders generated at build time.
BIN_PATH = bin
OBJ_PATH = obj
LOG_PATH = report

# Microcontroller name
DEVICE = STM32F429ZI

# Linker script file.
LINKER_SCRIP = ../src/init/linker/Stm32f429zi_Ls.ld

# Target name:
TARGET = $(BIN_PATH)/$(PROJECT)

# Microcontroller Processor Architecture:
MACH = cortex-m4

# Source directory:
SRC_PATH  = ../src
ASW_PATH  = $(SRC_PATH)/asw
BSW_PATH  = $(SRC_PATH)/bsw
FW_PATH   = $(SRC_PATH)/fw
INIT_PATH = $(SRC_PATH)/init

# Log file:
LOG_FILE = $(LOG_PATH)/report.log
LOG_CMD  = 2>&1 | tee -a $(LOG_FILE)

# Compiler variables:
CC = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump
DB = JLinkGDBServerCL
GDB = arm-none-eabi-gdb
SIZE = arm-none-eabi-size

#Flags
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -g

# Check if user has selected standard library integration.
STDLIB =
ifeq ($(STDLIB),Y)
    LFLAGS = -mcpu=$(MACH) -mthumb $(INC_PATH) --specs=nano.specs -T $(LINKER_SCRIP) -Wl,-Map=$(BIN_PATH)/$(PROJECT).map
	SYSCALLS = $(CC) $(CFLAGS) $(WARNS) $(INC_PATH) ../src/init/stdlib/syscalls.c -o $(OBJ_PATH)/syscalls.o
else
    LFLAGS = -mcpu=$(MACH) -mthumb $(INC_PATH) -nostdlib -T $(LINKER_SCRIP) -Wl,-Map=$(BIN_PATH)/$(PROJECT).map
	SYSCALLS = 
endif

.PHONY: all asw bsw clean client debug firmware flash init link post_build pre_build server stats

all: clean
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(LOG_PATH)
	@mkdir -p $(OBJ_PATH)
	@d=$$(gdate +%s); $(MAKE) "build" $(LOG_CMD) && echo "Building time: $$(gdate --utc --date=@$$(($$(gdate +%s)-d)) '+%H:%M:%S')" $(LOG_CMD)

asw:
	@echo ''
	@$(MAKE) -C $(ASW_PATH)

build: pre_build firmware bsw asw init link post_build stats

bsw:
	@echo ''
	@$(MAKE) -C $(BSW_PATH)

init:
	@echo ''
	@$(MAKE) -C $(INIT_PATH)
	@$(SYSCALLS)

clean:
	@echo $(PROJECT) "project: cleaning started!"
	@rm -rf $(BIN_PATH) $(OBJ_PATH) $(LOG_PATH)
	@echo $(PROJECT) "project: succesfully cleaned!!!"
	@echo''

firmware:
	@$(MAKE) -C $(FW_PATH)

link:
	@echo ''
	@echo "Linking ...!"
	$(CC) $(LFLAGS) $(OBJ_PATH)/*.o -o $(TARGET)
	@echo "Linking done!!!"

post_build:
	@echo ''
	@echo "Generating binary ...! "
	$(OC) -O binary $(TARGET) $(TARGET).bin
	@echo "Binary generated!!!"

pre_build:
	@echo $(PROJECT)
	@echo "Build date: "$(shell gdate '+%Y-%m-%d %H:%M:%S')
	@echo ''
	@echo "Building started...!"

stats:
	@echo ''
	@echo "Analyzing .elf ...!"
	$(OD) -h $(TARGET)
	@echo "Analysis done!!!"
	@echo ''
	$(SIZE) $(TARGET)
	@echo ''

################################### Flashing and debugging section #######################################
$(BIN_PATH)/jflash: $(TARGET).bin
	@touch $@
	@echo Device $(DEVICE) > $@
	@echo si 1'\n'Speed 4000 >> $@
	@echo loadbin $< 0x08000000 >> $@
	@echo r'\n'g'\n'qc >> $@

flash: $(BIN_PATH)/jflash
	@echo "Flashing started ...!"
	JLinkExe -commanderscript $<

# Use this if you are using JLink: make -j2 debug
debug: server client

client:
	$(GDB) -ex 'target remote: 2331' $(TARGET) 

server:
	$(DB) -select USB -device $(DEVICE) -endian-little -if SWD -speed 4000