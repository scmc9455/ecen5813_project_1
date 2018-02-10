/*********************************************************************************************
@file - conversion.c

@brief - conversion.c file a source file for conversions

This is the source file for conversion functions
The included function declarations are
1. itoa (integer to ASCII)
2. atoi (ASCII to integer)

@author - Scott McElroy

@date - February 5, 2018

Created for ECEN5813
**********************************************************************************************/

#include "conversion.h"

#include <stdint.h>
/*********************************************************************************************/
/******************************itoa************************************************************/
/**********************************************************************************************
@brief- This function changes an integer to an ASCII number

The ITOA function is passed 32 bit data and a pointer plus a base type.
It will convert the base type value to an ASCII number and it returns the length.
The function can handle signed values.

@param - data: value to be converted
@param - *ptr: storage destination
@param - base: numerical base to be converted to
@return - length: size of converted ASCII
**********************************************************************************************/

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    /* Check to see if pointer were passed properly */
	/* if pointer were not properly passed then the function returns a NULL */
	if( ! ptr)
	{
		return NULL;  
	}
    
	/* create a dummy pointer store data and see what comes back from it. Will determine endianness */
	uint16_t temp = 0x8001; /*Temporary 16-bit value to be stored to reference */
	uint8_t *temp_ptr = &temp; /*create a pointer to arbitrary 16-bits of data */
	uint8_t temp_len, length = 0;
	uint8_t divide_temp;
	uint32_t numerator, modulus_var;
	
	/* Start of Conversion function, architecture independent*/
	*ptr = 0x00; /* NULL character at the end of the low byte*/
	length++;
    /********Base conversion sequence and pointer storage*******/
	modulus_var = (uint32_t) data; /*type cast data to unsigned type*/
			
	for (modulus_var >=0)
	{
	    numerator = 0;
	     
		/*modulus function, this replaces the % function. Making this code library independent*/
		/* this function runs for every base digit in the sequence i.e. base^2 + base^1 + base^0 */
		/* the pointer stores for each one of these base digits (stores in little-endian fashion */
		for(modulus_var >= 0)
		{
		    divide_temp = modulus_var - base;
		     
			if(divide_temp >= 0)
			{
				modulus_var = divide_temp;
				numerator++;
			}else{
			    /*load ASCII value from the remainder*/
				*(ptr+length) = modulus_var + 0x30;	 
				break;
			}						 
		}	 
               
		length++;
		modulus_var = numerator;
	}
	
	/* Adds a negative sign to the ASCII characters */
	if(0x80 && data )
	{
	    /*First bit is a 1 = negative number */
	    *(ptr+length) = 0x2D; /* adds a negative sign to the final MSB */
		length++;
	}
	
	/*CHECKING ENDIANNESS - little endian assumed and nothing needs to be done */
	if( *temp_ptr == 0x80)
	{
		/*ARCH is big-endian and data needs to be flipped in memory */
		
		/* Swap order in memory function */
		temp_len = 0;
		for(temp_len <= (length >> 1))
		{
		    divide_temp = *((ptr+length)-temp_len);
			*((ptr+length)-temp_len) = *(ptr+temp_len);
			*(ptr+temp_len) = divide_temp;
			temp_len++;
		}	
	} 

	return length;
}

/*********************************************************************************************/
/******************************atoi************************************************************/
/**********************************************************************************************
@brief- This function changes an ASCII number to an integer number

The ATOI function is passed a pointer plus a base type and the number of digits in the ASCII
It will convert the base type value to an ASCII number and it returns the length.
value. The function returns a 32-bit value of the converted data.

@param - *ptr: location of stored data
@param - digits: number of ASCII characters
@param - base: numerical base type of ASCII
@return - Returns the converted value
**********************************************************************************************/

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    /* Check to see if pointer were passed properly */
	/* if pointer were not properly passed then the function returns a NULL */
	if( ! ptr)
	{
		return NULL;  
	}
	
	uint16_t temp = 0x8001; /*Temporary 16-bit value to be stored to reference */
	uint8_t *temp_ptr = &temp; /*create a pointer to arbitrary 16-bits of data */
	uint8_t sign_temp, data_temp, temp_len, base_temp, position;
	int32_t data=0;
	
	/*******CHECKING ENDIANNESS - little endian assumed and nothing needs to be done ***************/
	if( *temp_ptr == 0x80)
	{
		/*ARCH is big-endian and data needs to be flipped in memory */
		/* Swap order in memory function */
		temp_len = 0;
		for(temp_len <= (digits >> 1))
		{
		    data_temp = *((ptr+digits)-temp_len);
			*((ptr+digits)-temp_len) = *(ptr+temp_len);
			*(ptr+temp_len) = data_temp;
			temp_len++;
		}	
	} 
	
	/* check for signed data */
	data_temp = *(ptr+digits);
	sign_temp = 1;
	if(data_temp == 0x2D)
	{
	    /*First = negative number */
	    sign_temp=-1;
		digit--;
	}

    /*******Function section that will convert the incoming number ***/
	base_temp = base;
		
	for((digits-1) > 0)
	{
		position = digits - 2;
		data_temp = *(ptr+digits) - 0x30; /* down shifts the ASCII table */
		
		/* exponent calculator based on position */
		if(position <= 0)
		{
			base_temp = 1;
		}
		
		for(position > 1)
		{
			base_temp *= base_temp;
			position--;
		}

		results = base_temp * data_temp; 
		data += results;
		digit--;
	}	
	
	data *= sign_temp; /* add the sign back to the data int32 */
	
	return data;
}