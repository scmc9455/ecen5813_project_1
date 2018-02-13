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
LDFLAGS:= -Wl,-Map=main.map
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
INCLUDES = -I./../include/common \
-I./../include/kl25z \
-I./../include/CMSIS \
-I./../platform
LDFLAGS += -T../platform/MKL25Z128xxx4_flash.ld
else ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabi-gcc
CPPFLAGS = -DBBB	
CFLAGS = $(GENFLAGS) $(CPPFLAGS) -DVERBOSE
INCLUDES = -I./../include/common \
-I./../include/CMSIS

else ifeq ($(PLATFORM),HOST)
CC = gcc
CPPFLAGS = -DHOST
CFLAGS = $(GENFLAGS) $(CPPFLAGS) -DVERBOSE
INCLUDES:= -I./../include/common \
-I./../include/CMSIS

#this will default to the native compiler
else 
CC= gcc
CFLAG = $(GENFLAGS) -DVERBOSE
CPPFLAGS = -DHOST
INCLUDES:= -I./../include/common

endif	

#******************************************************************************
#**********Command "make build"*******************************************
.PHONY: build
build: $(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) $(OBJS) -o $(TARGET)

#**********Command "make clean"*******************************************
.PHONY: clean
clean:
	rm -f *.o *.i *.asm *.elf *.dep *.map

#**********Command "make size"*********************************************
.PHONY: size
size: 
	size $(OBJS) $(TARGET)

#*************Create only all dependency files**************************
$(DEPS):$(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) $@ -M -o $^ 

#******This section will generate the assembly files*********************
memory.asm:memory.c
	$(CC) $(CFLAGS) $(INCLUDES) memory.c -S -o memory.asm

project1.asm:project1.c
	$(CC) $(CFLAGS) $(INCLUDES) project1.c -S -o project1.asm

data1.asm:data1.c
	$(CC) $(CFLAGS) $(INCLUDES) data1.c -S -o data1.asm

debug.asm:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) debug.c -S -o debug.asm

conversion.asm:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) conversion.S -c -o conversion.asm

main.asm:main.c
	$(CC) $(CFLAGS) $(INCLUDES) main.c -S -o main.asm 

arch_arm32.asm:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) arch_arm32.c -S -o arch_arm32.asm

#******This section will generate the preprocessed files*****************
memory.i:memory.c
	$(CC) $(CFLAGS) $(INCLUDES)  memory.c -E -o memory.i

project1.i:project1.c
	$(CC) $(CFLAGS) $(INCLUDES)  project1.c -E -o project1.i

data1.i:data.c
	$(CC) $(CFLAGS) $(INCLUDES) data1.c -E -o data1.i 

debug.i:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) debug.c -E -o debug.i 

conversion.i:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) conversion.c -E -o conversion.i 

main.i:main.c
	$(CC) $(CFLAGS) $(INCLUDES) main.c -E -o main.i 

arch_arm32.i:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) arch_arm32.c -E -o arch_arm32.i 

#**********Command "make compile-all"*************************************
.PHONY: compile-all
compile-all: $(OBJS)
#*******Create only all object files*************************************
memory.o:memory.c
	$(CC) $(CFLAGS) $(INCLUDES) memory.c -c -o memory.o

project1.o:project1.c
	$(CC) $(CFLAGS) $(INCLUDES) project1.c -c -o project1.o

data1.o:data1.c
	$(CC) $(CFLAGS) $(INCLUDES) data1.c -c -o data1.o

debug.o:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) debug.c -c -o debug.o

conversion.o:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) conversion.c -c -o conversion.o

main.o:main.c
	$(CC) $(CFLAGS) $(INCLUDES) main.c -c -o main.o

arch_arm32.o:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) arch_arm32.c -c -o arch_arm32.o

#**************************End of File************************************
#************************************************************************

