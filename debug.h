/*********************************************************************************************
@file - debug.h

@brief - debug.h file a header file for the debug function

This is the header file for the debug function
The included function declarations are
1. print_array

@author - Scott McElroy

@date: Feburary 5, 2018

Created for ECEN5813
**********************************************************************************************/

#ifndef _DEBUG_H_
#def    _DEBUG_H_

#include <stdlib.h>
#include <stdint.h>

/*********************************************************************************************/
/******************************print_array****************************************************/
/**********************************************************************************************
@brief- This function allows for debug using a print array

The print array function is passed a pointer plus a length.
This function takes whatever data is at the memory location and prints the hex output for 
in bytes by the specified number.

@param - NA
@return - NA
**********************************************************************************************/

void print_array(uint8_t *start, uint32_t length);

#endif /* _DEBUG_H_ */