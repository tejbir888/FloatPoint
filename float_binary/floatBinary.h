///This project is to convert a floating point number to binary representation as per IEEE754 standards///

/// Headers ///
#include <stdio.h>

//// Macro definitions ///
#define MASK_MANTISSA 0x007fffff
#define MASK_EXPONENT 0x7f800000
#define BIT_SHIFT_SIGN 31
#define BIT_SHIFT_EXPONENT 23
#define NUMBER_BITS_FOR_EXPONENT 8
#define NUMBER_BITS_FOR_MANTISSA 23

//Function declarations ///
void printNumberInBinary(int n, int i);
int get_sign_value(unsigned int *ptr);
int get_exponent_value(unsigned int *ptr);
int get_mantissa_value(unsigned int *ptr);
