#**************************************************************************#
#@file - source.mk
#
#@breif - This is the sources Makefile that will be includede in the make
#
#@author - Scott McElroy
#
#@data - February 11, 2018
#
#**************************************************************************#

#Compile time switch for the makefile
ifeq ($(PLATFORM),KL25Z)
SRCS = ./data1.c ./debug.c ./memory.c ./conversion.c \
./project1.c ./arch_arm32.c ./main.c \
./startup_MKL25Z4.S ./system_MKL25Z4.c
else ifeq ($(PLATFORM),BBB)
SRCS = ./data1.c ./debug.c ./memory.c ./conversion.c \
./project1.c ./main.c
else ifeq ($(PLATFORM),HOST)
SRCS = ./data1.c ./debug.c ./memory.c ./conversion.c \
./project1.c ./main.c
#if no platform is speced, make defaults to native compiler
else
SRCS = ./data1.c ./debug.c ./memory.c ./conversion.c \
./project1.c ./main.c
endif
