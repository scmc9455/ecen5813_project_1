#**************************************************************************#
#@file - Makefile
#
#@breif - This is the Makefile that will compiler the project1 executable
#
#@author - Scott McElroy
#
#@data - February 11, 2018
#
#**************************************************************************#

include sources.mk

#***********Variables******
GENFLAGS:= -Wall -Werror -g -O0 -std=c99
LDFLAGS:= -Xlinker -Map=project1.map
OBJS:= $(SRCS:.c=.o)
DEPS:= $(SRCS:.c=.dep)
PREPRO:= $(SRCS:.c=.i)
ASM:= $(SRCS:.c=.asm)
TARGET:= project1.elf

#SRC defined in sources.mk
#Includes defined in source.mk file
#
#**************Switch statements for the platform determination**********
ifeq ($(PLATFORM),KL25Z)
CPU = cortex-m0plus
CC = arm-none-eabi-gcc
ARCH= armv6-m
CPPFLAGS = -DKL25Z	
CFLAGS = $(GENFLAGS) -march=$(ARCH) -mcpu=$(CPU) -mthumb \
-mfloat-abi=soft -mfpu=fpv4-sp-d16 --specs=nosys.specs \
$(CPPFLAGS)
INCLUDES = -l./../repos/ecen5813_project_1/include/common \
-l./../repos/ecen5813_project_1/include/kl25z \
-l./../repos/ecen5813_project_1/include/CMSIS \
-l./../repos/ecen5813_project_1/platform
else ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabi-gcc
CPPFLAGS = -DBBB	
CFLAGS = $(GENFLAGS) $(CPPFLAGS) -DVERBOSE
INCLUDES = -l./../repos/ecen5813_project_1/include/common \
-l./../include/CMSIS

else ifeq ($(PLATFORM),HOST)
CC = gcc
CPPFLAGS = -DHOST
CFLAGS = $(GENFLAGS) $(CPPFLAGS) -DVERBOSE
INCLUDES:= -l./../repos/ecen5813_project_1/include/common

#this will default to the native compiler
else 
CC= gcc
CFLAG = $(GENFLAGS) -DVERBOSE
CPPFLAGS = -DHOST
INCLUDES:= -l./../include/common

endif	

#******************************************************************************
#**********Command "make clean"*******************************************
.PHONY: clean
clean:
	rm -f $(OBJS) $(PREPRO) $(ASM) $(TARGET) $(DEPS) project1.map

#**********Command "make size"*********************************************
.PHONY: size
size: 
	size $(OBJS) $(TARGET)

#**********Command "make build"*******************************************
.PHONY: build
target:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -o $@ $^

#**********Command "make compile-all"*************************************
.PHONY: compile-all
target:$(OBJS)
$(OBJS):$(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -c $@ $^ 

#*************Create only all dependency files**************************
$(DEPS):$(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -M $@ $^ 

#*******Create only all object files*************************************
memory.o:memory.c
	$(CC) $(CFLAGS) $(INCLUDES) -c memory.o memory.c

project1.o:project1.c
	$(CC) $(CFLAGS) $(INCLUDES) -c project.o project1.c

data.o:data.c
	$(CC) $(CFLAGS) $(INCLUDES) -c data.o data.c

debug.o:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) -c debug.o debug.c

conversion.o:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) -c conversion.o conversion.c

main.o:main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c main.o main.c

arch_arm32.o:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) -c arch_arm32.o arch_arm32.c

#******This section will generate the assembly files*********************
memory.asm:memory.c
	$(CC) $(CFLAGS) $(INCLUDES) -c memory.asm memory.c

project1.asm:project1.c
	$(CC) $(CFLAGS) $(INCLUDES) -c project1.asm project1.c

data.asm:data.c
	$(CC) $(CFLAGS) $(INCLUDES) -c data.asm data.c

debug.asm:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) -c debug.asm debug.c

conversion.asm:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) -c conversion.asm conversion.c

main.asm:main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c main.asm main.c

arch_arm32.asm:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) -c arch_arm32.asm arch_arm32.c

#******This section will generate the preprocessed files*****************
memory.i:memory.c
	$(CC) $(CFLAGS) $(INCLUDES) -c memory.i memory.c

project1.i:project1.c
	$(CC) $(CFLAGS) $(INCLUDES) -c project1.i project1.c

data.i:data.c
	$(CC) $(CFLAGS) $(INCLUDES) -c data.i data.c

debug.i:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) -c debug.i debug.c

conversion.i:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) -c conversion.i conversion.c

main.i:main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c main.i main.c

arch_arm32.i:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) -c arch_arm32.i arch_arm32.c

#**************************End of File************************************
#************************************************************************

