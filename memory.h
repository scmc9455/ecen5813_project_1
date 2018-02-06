/*********************************************************************************************
@file - memory.h

@brief - Memory.h file is the header file for memory manipulation functions

This is the header file for memory functions in "memory.c"
The included function declarations are
1. memmove
2. memcpy
3. memset
4. memzero
5. reverse
6. reverse_words
7. free_words

@author - Scott McElroy

@date: Feburary 5, 2018

Created for ECEN5813
**********************************************************************************************/

#ifndef _MEMORY_H_
#def    _MEMORY_H_

#include <stdlib.h>
#include <stdint.h>

/********************************************************************************************
@brief - moves memory from one location to another

The memmove function is passed a source and destination address,
the contents at the source address get temporarily copied completely 
depending on the length specified when called and then moved to the
destination address.
This function is a non-corruption based moved even if the source and 
destination is overlapping.

@param - NA
@return - Returns the destination pointer address
********************************************************************************************/

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/********************************************************************************************
@brief - this is a memory coping function from one location to another

The memcpy function is passed a source and destination address,
the contents is directly passed to the destinaion address
This function could be destructive if the dst overrides the source.

@param - NA
@return - Returns the destination address of copied data
*********************************************************************************************/

uint8_t *my_memcpy(uint8_t *src, uint8_t *dst, size_t length);

/**********************************************************************************************
@brief - This function set a block of memory to a certain value

The memset function is passed a source address and a value,
the value that is passed on a function call is put into the destinaion address

@param - NA
@return - Returns the location of source address
**********************************************************************************************/

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value);

/**********************************************************************************************
@brief- This function zeros out a block of memory

The memzero function is passed a source address and a length,
the function zeros out all of the memory for the specified length.

@param - NA
@return - Returns the source address of the zeroed block
**********************************************************************************************/

uint8_t *my_memzero(uint8_t *src, size_t length);

/**********************************************************************************************
@brief - This function reverse a block of memory by bytes

The reverse function is passed a source address and a length,
the function revereses the order of the memory based on the length.

@param - NA
@return - Returns a source address of the memory block that was reverse
**********************************************************************************************/

uint8_t *my_reverse(uint8_t *src, size_t length);

/**********************************************************************************************
@brief - This function dynamically reserve a block of memory

The reserve function is passed a length,
the function reserves the memory based on the length so memory can be dynamically allocated.
The function returns the location of the newly allocated memory.

@param - NA
@return - Returns the location address of the reserved memory block
**********************************************************************************************/

void *reserve_words(size_t length);

/**********************************************************************************************
brief - This functions frees a block of memory that was reserved

The free function is passed a source address,
the function frees up the memory that has been dynamically allocated.

@param - NA
@return - Returns a 0 if successful and 1 if it fails
**********************************************************************************************/

uint8_t free_words(void *src);

#endif /*_MEMORY_H_ */