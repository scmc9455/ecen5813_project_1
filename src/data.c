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
#include "platform.h"
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
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
    /*Compiler directive to ignore the emtpy variable when the KL25z doesnt use printf*/
    #if defined (__GNUC__)
    #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    #endif
    /*Variable temp configuration below used from project documentation*/
    size_t temp;
    /*below prints the size of respective type based on the project 1 documentation*/
    temp = sizeof(char);
    PRINT("Char %zd", temp);

    temp = sizeof(short);
    PRINT("Short %zd", temp);

    temp = sizeof(int);
    PRINT("Int %zd", temp);

    temp = sizeof(long);
    PRINT("Long %zd", temp);

    temp = sizeof(double);
    PRINT("Double %zd", temp);

    temp = sizeof(float);
    PRINT("Float %zd", temp);

    temp = sizeof(unsigned char);
    PRINT("Unsigner char %zd", temp);
	
    temp = sizeof(unsigned int);
    PRINT("Unsigned int %zd", temp);

    temp = sizeof(unsigned long);
    PRINT("Unsigned long %zd", temp);

    temp = sizeof(signed char);
    PRINT("Signed char %zd", temp);

    temp = sizeof(signed int);
    PRINT("Signed int %zd", temp);

    temp = sizeof(signed long);
    PRINT("Signed long %zd", temp);

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
    /*Compiler directive to ignore the emtpy variable when the KL25z doesnt use printf*/
    #if defined (__GNUC__)
    #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    #endif
    /*Variable temp configuration below used from project documentation*/
    size_t temp;
    /*below prints the size of respective type based on the project 1 documentation*/
    temp = sizeof(int8_t);
    PRINT("int8_t %zd", temp);

    temp = sizeof(uint8_t);
    PRINT("uint8_t %zd", temp);

    temp = sizeof(int16_t);
    PRINT("int16_t %zd", temp);

    temp = sizeof(uint16_t);
    PRINT("uint16_t %zd", temp);

    temp = sizeof(int32_t);
    PRINT("int32_t %zd", temp);

    temp = sizeof(uint32_t);
    PRINT("uint32_t %zd", temp);

    temp = sizeof(uint_fast8_t);
    PRINT("uint_fast8_t %zd", temp);

    temp = sizeof(uint_fast16_t);
    PRINT("uint_fast16_t %zd", temp);

    temp = sizeof(uint_fast32_t);
    PRINT("uint_fast32_t %zd", temp);

    temp = sizeof(uint_least8_t);
    PRINT("uint_least8_t %zd", temp);

    temp = sizeof(uint_least16_t);
    PRINT("uint_least16_t %zd", temp);

    temp = sizeof(uint_least32_t);
    PRINT("uint_least32_t %zd", temp);

    temp = sizeof(size_t);
    PRINT("size_t %zd", temp);

    temp = sizeof(ptrdiff_t);
    PRINT("ptrdiff_t %zd", temp);	
	
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
    /*Compiler directive to ignore the emtpy variable when the KL25z doesnt use printf*/
    #if defined (__GNUC__)
    #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    #endif
    /*Variable temp configuration below used from project documentation*/
    size_t temp;
    /*below prints the size of respective type based on the project 1 documentation*/
    temp = sizeof(char *);
    PRINT("Char * %zd", temp);

    temp = sizeof(short *);
    PRINT("Short * %zd", temp);

    temp = sizeof(int *);
    PRINT("Int * %zd", temp);

    temp = sizeof(long *);
    PRINT("Long * %zd", temp);

    temp = sizeof(double *);
    PRINT("Double * %zd", temp);

    temp = sizeof(float *);
    PRINT("Float * %zd", temp);

    temp = sizeof(void *);
    PRINT("Void * %zd", temp);

    temp = sizeof(int8_t *);
    PRINT("Int8_t * %zd", temp);

    temp = sizeof(int16_t *);
    PRINT("Int16_t * %zd", temp);

    temp = sizeof(int32_t *);
    PRINT("Int32_t * %zd", temp);

    temp = sizeof(char **);
    PRINT("Char ** %zd", temp);

    temp = sizeof(int **);
    PRINT("Int ** %zd", temp);

    temp = sizeof(void **);
    PRINT("Void ** %zd", temp);

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
    if(data == NULL)
    {
        return SWAP_ERROR; /* returns SWAP_ERROR from NULL pointer input */
    }
	
    uint32_t temp_len = 0;
    uint32_t data_temp;

    while(temp_len <= (type_length/2))
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
    uint16_t *temp_ptr = &temp; /*create a pointer to arbitrary 16-bits of data */

    if( *(uint8_t *)temp_ptr == 0x80)
    {
        /*The value got stored with the high-byte at the low pointer value*/
        return _BIG_ENDIAN;
    }else{
        return _LITTLE_ENDIAN;
    }	
}
