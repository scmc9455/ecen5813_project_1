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
	SRCS = ./data.c ./debug.c ./memory.c ./conversion.c \
	       ./project.c ./arch_arm32.c main.c
	       ./startup_MKL25Z4.s ./system_MKL25Z4.c
	
	INCLUDES = -l./../include/common -l./../include/kl25z \
                   -l./../include/CMSIS -l./../platform

else ifeq ($(PLATFORM),BBB)
	SRCS = ./data.c ./debug.c ./memory.c ./conversion.c \
	       ./project.c ./main.c

	INCLUDES = -l./../include/common -l./../include/CMSIS

else ($(PLATFORM),HOST)
	SRCS = ./data.c ./debug.c ./memory.c ./conversion.c \
	       ./project.c ./main.c

	INCLUDES:= -l./../include/common
#if no platform is speced, make defaults to native compiler
else
	SRCS = ./data.c ./debug.c ./memory.c ./conversion.c \
	       ./project.c ./main.c
	INCLUDES:= -l./../include/common

endif
