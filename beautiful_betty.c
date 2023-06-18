#include <stdio.h>

/**
*multiply_numbers - multiplies two numbers
*@y: first number to multiply
*@a: second number to multiply
*
*Return: multiplication of two the  numbers
*/
int multiply_numbers(int y, int a)
{
	return (y * a);
}

/**
*main - Entry
*Return: 0
*/

int main(void)
{
	int y = 25, a = 1;
	int multiply;

	multiply = multiply_numbers(y, a);
	printf("multiplication of %d and %d is %d\n", y, a, multiply);

	return (0);
}
