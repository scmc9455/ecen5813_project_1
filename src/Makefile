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
LDFLAGS:= -WI -Map=project1.map
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
	
else ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabi-gcc
	CPPFLAGS = -DBBB	
	CFLAGS = $(GENFLAGS) $(CPPFLAGS) -DVERBOSE
	

else ifeq ($(PLATFORM),HOST)
	CC = gcc
	CPPFLAGS = -DHOST
	CFLAGS = $(GENFLAGS) $(CPPFLAGS) -DVERBOSE


#this will default to the native compiler
else 
	CC= gcc
	CFLAG = $(GENFLAGS) -DVERBOSE
	CPPFLAGS = -DHOST
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
target: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -o $@ $^

#**********Command "make compile-all"*************************************
.PHONY: compile-all
target: $(OBJS)
$(OBJS): $(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -c $@ $^ 

#*************Create only all dependency files**************************
$(DEPS): $(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -M $@ $^ 

#*******Create only all object files*************************************
memory.o:memory.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

project1.o:project1.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

data.o:data.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

debug.o:debug.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

conversion.o:conversion.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

main.o:main.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

arch_arm32.o:arch_arm32.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

#******This section will generate the assembly files*********************
memory.asm:memory.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

project1.asm:project1.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

data.asm:data.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

debug.asm:debug.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

conversion.asm:conversion.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

main.asm:main.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

arch_arm32.asm:arch_arm32.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

#******This section will generate the preprocessed files*****************
memory.i:memory.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

project1.i:project1.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

data.i:data.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

debug.i:debug.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

conversion.i:conversion.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

main.i:main.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

arch_arm32.i:arch_arm32.c
	$(CC) $(CFLAG) $(INCLUDES) -c $@ $^

#**************************End of File************************************
#************************************************************************

