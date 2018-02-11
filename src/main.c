/*********************************************************************************************
@file - main.c

@brief - main program header file

This program only calls functions from project1
This also include all the necessary libraries and headers that are used in each of the files

@author - Scott McElroy

@date - February 9, 2018

Created for ECEN5813
**********************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "MKL25Z4.h"
#include "project.h"
#include "memory.h"
#include "conversion.h"
#include "debug.h"
#include "data.h"

void main(void)
{
	
    /* Call program only calls functions from project1() using a compile time switch */
    project1();
	
    while(1)
    {	
        /* infinite loop in code */
    }
}
