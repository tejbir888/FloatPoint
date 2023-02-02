///This project is to convert a floating point number to binary representation as per IEEE754 standards///

#include "floatBinary.h"

/// @brief This method print bits for a number
/// @param n number for which to generate binary
/// @param i number of bits
/// @return void

void printNumberInBinary(int n, int i)
{
	int k;
	for (k = i - 1; k >= 0; k--) {
		if ((n >> k) & 1)
			printf("1");
		else
			printf("0");
	}
}

/// @brief This method returns the 32nd bit sign value
/// @param ptr to the actual number
/// @return integer sign number

int get_sign_value(unsigned int *ptr)
{
	return ((*ptr) >> BIT_SHIFT_SIGN);
}

/// @brief This method returns the exponent value
/// @param ptr pointer to the actual number
/// @return integer exponent number

int get_exponent_value(unsigned int *ptr)
{
	int exp; 
	exp = *ptr & MASK_EXPONENT;
        return (exp >>= BIT_SHIFT_EXPONENT);
}

/// @brief This method returns the mantisa value
/// @param ptr pointer to the actual number
/// @return integer mantissa number

int get_mantissa_value(unsigned int *ptr)
{
	return ((*ptr) & MASK_MANTISSA);
}

/// @brief This method is the main
/// @return integer

int main()
{
	float var = 0.0;
	printf("Enter the float value:");
	scanf("%f", &var);
	
	unsigned int* ptr = (unsigned int*)&var;
	printf("\nSign \tMantissa \t \t \tExponent \n");
	printf("---------------------------------------------------\n");
	printf("%d \t", get_sign_value(ptr));
	printNumberInBinary(get_exponent_value(ptr), NUMBER_BITS_FOR_EXPONENT);
	printf("\t \t \t");
	printNumberInBinary(get_mantissa_value(ptr), NUMBER_BITS_FOR_MANTISSA);
	printf("\n");
   
	return 0;
}
