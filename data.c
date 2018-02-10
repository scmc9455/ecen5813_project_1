/*********************************************************************************************
@file - data.c

@brief - data.c file is the source file for the data conversion functions

This file is the source for the data.c file and includes the functions
1. print_cstd_type_sizes()
2. print_stdint_type_sizes()
3. print_pointer_sizes()
4. swap_data_endianness
5. determine_endianness

@author - Scott McElroy

@date - February 7, 2018

Created for ECEN5813
**********************************************************************************************/

#include "data.h"
#include <stdint.h>
#include <stdio.h>

/*********************************************************************************************/
/***********************print_cstd_type_sizes*****************************************************/
/**********************************************************************************************
@brief- This function print the standard size types

Reports - Char, short, int, long, double, float, unsigned char, unsigned int, unsigned long

@param - none
@return - void
**********************************************************************************************/

void print_cstd_type_sizes()
{
	#if defined (__GNUC__)
	#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
	#endif
	
	size_t temp_var;
	
	temp_var = sizeof(char);
	printf("Size of Char = %d", temp_var);
	
	temp_var = sizeof(short);
	printf("Size of Short = %d", temp_var);
	
	temp_var = sizeof(int);
	printf("Size of Int = %d", temp_var);
	
	temp_var = sizeof(long);
	printf("Size of Long = %d", temp_var);
	
	temp_var = sizeof(double);
	printf("Size of Double = %d", temp_var);
	
	temp_var = sizeof(float);
	printf("Size of Float = %d", temp_var);
	
	temp_var = sizeof(unsigned char);
	printf("Size of Unsigner char = %d", temp_var);
	
	temp_var = sizeof(unsigned int);
	printf("Size of Unsigned int = %d", temp_var);
	
	temp_var = sizeof(unsigned long);
	printf("Size of Unsigned long = %d", temp_var);
	
	temp_var = sizeof(signed char);
	printf("Size of Signed char = %d", temp_var);
	
	temp_var = sizeof(signed int);
	printf("Size of Signed int = %d", temp_var);
	
	temp_var = sizeof(signed long);
	printf("Size of Signed long = %d", temp_var);

	return;
}

/*********************************************************************************************/
/******************************print_stdint_type_sizes********************************************/
/**********************************************************************************************
@brief- This function print the standard int type sizes

Reports int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t, uint_fast8_t, uint_fast16_t, uint_fast32_t,
uint_least8_t, uint_least16_t, uint_least32_t, size_t, ptrdiff_t

@param - none
@return - void
**********************************************************************************************/

void print_stdint_type_sizes()
{
	#if defined (__GNUC__)
	#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
	#endif

	size_t temp_var;
	
	temp_var = sizeof(int8_t);
	printf("Size of int8_t = %d", temp_var);
	
	temp_var = sizeof(uint8_t);
	printf("Size of uint8_t = %d", temp_var);
	
	temp_var = sizeof(int16_t);
	printf("Size of int16_t = %d", temp_var);
	
	temp_var = sizeof(uint16_t);
	printf("Size of uint16_t = %d", temp_var);
	
	temp_var = sizeof(int32_t);
	printf("Size of int32_t = %d", temp_var);
	
	temp_var = sizeof(uint32_t);
	printf("Size of uint32_t = %d", temp_var);
	
	temp_var = sizeof(uint_fast8_t);
	printf("Size of uint_fast8_t = %d", temp_var);
	
	temp_var = sizeof(uint_fast16_t);
	printf("Size of uint_fast16_t = %d", temp_var);
	
	temp_var = sizeof(uint_fast32_t);
	printf("Size of uint_fast32_t = %d", temp_var);
	
	temp_var = sizeof(uint_least8_t);
	printf("Size of uint_least8_t = %d", temp_var);
	
	temp_var = sizeof(uint_least16_t);
	printf("Size of uint_least16_t = %d", temp_var);
	
	temp_var = sizeof(uint_least32_t);
	printf("Size of uint_least32_t = %d", temp_var);

	temp_var = sizeof(size_t);
	printf("Size of size_t = %d", temp_var);

	temp_var = sizeof(ptrdiff_t);
	printf("Size of ptrdiff_t = %d", temp_var);	
	
	return;	
}

/*********************************************************************************************/
/******************************print_pointer_sizes************************************************/
/**********************************************************************************************
@brief- This function print the standard pointer type sizes

Reports char *, short *, int *, long *, double *, float *, void *, int8_t *, int16_t *, int32_t *, char **, int **, void **

@param - none
@return - void
**********************************************************************************************/

void print_pointer_sizes()
{
	#if defined (__GNUC__)
	#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
	#endif

	size_t temp_var;
	
	temp_var = sizeof(char *);
	printf("Size of Char * = %d", temp_var);
	
	temp_var = sizeof(short *);
	printf("Size of Short * = %d", temp_var);
	
	temp_var = sizeof(int *);
	printf("Size of Int * = %d", temp_var);
	
	temp_var = sizeof(long *);
	printf("Size of Long * = %d", temp_var);
	
	temp_var = sizeof(double *);
	printf("Size of Double * = %d", temp_var);
	
	temp_var = sizeof(float *);
	printf("Size of Float * = %d", temp_var);
	
	temp_var = sizeof(void *);
	printf("Size of Void * = %d", temp_var);
	
	temp_var = sizeof(int8_t *);
	printf("Size of Int8_t * = %d", temp_var);
	
	temp_var = sizeof(int16_t *);
	printf("Size of Int16_t * = %d", temp_var);
	
	temp_var = sizeof(int32_t *);
	printf("Size of Int32_t * = %d", temp_var);
	
	temp_var = sizeof(char **);
	printf("Size of Char ** = %d", temp_var);
	
	temp_var = sizeof(int **);
	printf("Size of Int ** = %d", temp_var);

	temp_var = sizeof(void **);
	printf("Size of Void ** = %d", temp_var);

	return;	
}

/*********************************************************************************************/
/******************************swap_data_endianness*********************************************/
/**********************************************************************************************
@brief- This function converts endianness of data in memory

Given an address of data and size, this function will flip the data in memory

@param - data: source address of memory to be flipped
@param - type_length: amount of memory to be flipped
@return - SWAP_ERROR/NO_ERROR: successfulness
**********************************************************************************************/

int32_t swap_data_endianness(uint8_t *data, size_t type_length)
{
	if(! data)
	{
	    return SWAP_ERROR; /* returns SWAP_ERROR from NULL pointer input */
	}
	
	uint32_t temp_len = 0;
	uint32_t data_temp;
	
	for(temp_len <= (type_length/2))
	{
	    data_temp = *((data+type_length)-temp_len);
		*((data+type_length)-temp_len) = *(data+temp_len);
		*(data+temp_len) = data_temp;
		temp_len++;
	}

	if( temp_len == (type_length/2))
    {
		return SWAP_NO_ERROR;
	}else{
        return SWAP_ERROR;
    }	
}

/*********************************************************************************************/
/********************determine_endianness*******************************************************/
/**********************************************************************************************
@brief- This function determines the endianness of data in memory

This will report back what the data endianness is so it can be changed if need be

@param - none
@return - value of endianness
**********************************************************************************************/

uint32_t determine_endianness()
{
    uint16_t temp = 0x8001; /*Temporary 16-bit value to be stored to reference */
	uint8_t *temp_ptr = &temp; /*create a pointer to arbitrary 16-bits of data */
	
	if( *temp_ptr == 0x80)
	{
		/*The value got stored with the high-byte at the low pointer value*/
		return BIG_ENDIAN;
	}else{
        return LITTLE_ENDIAN;
    }	
}
