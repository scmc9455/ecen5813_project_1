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

include source.mk

#***********Variables******
GENFLAGS = -Wall -Werror -g -O0 -std=c99
LDFLAGS = -Xlinker -Map=project1.map
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.dep)
PREPRO = $(SRCS:.c=.i)
ASM = $(SRCS:.c=.asm)
TARGET = project1.elf

#SRC defined in sources.mk
#Includes defined in source.mk file
#
#**************Switch statements for the platform determination**********
ifeq ($(PLATFORM),KL25Z)
	CPU = cortex-m0plus
	CC = arm-none-eabi-gcc
	ARCH= arm6v-m
	CPPFLAGS = -DKL25Z	
	CFLAGS = $(GENFLAGS) -march=$(ARCH) -mcpu=$(CPU) -mthumb \
		 -mfloat-abi=?? -mfpu=fpv4-sp-d16 --specs=nosys.specs \
		 $(CPPFLAGS)
	
else ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabi-gcc
	ARCH = 
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
#This will be the targeted output executeable file that runs with ./project1.elf



#*************Create only all dep files**************************
$(DEPS): $(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -M $@ $^

#******This section will generate the preprocessed files*************
$(PREPRO): $(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -E $@ $^

#******This section will generate the assembly files*************
$(ASM): $(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -S $@ $^

#*******Create only all object files*****************************
$(OBJS): $(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -c $@ $^

#**********Command "make compile-all"*****************************
.PHONY: compile-all
target: $(OBJS)
$(OBJS): $(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -c $@ $^

#**********Command "make build"**********************************
.PHONY: build
target: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) -o $@ $^

#**********Command "make build"**********************************
.PHONY: clean
target: 
	rm


