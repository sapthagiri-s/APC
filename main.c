#include "Apc.h" // Include the header file containing function declarations and definitions

int main(int argc, char *argv[])
{
	int flag1 = 0, flag2 = 0; // Flags to track the sign of the numbers

	D_list *data1 = NULL, *data2 = NULL; // Pointers to store the input numbers as linked lists
	S_list *res = NULL;					 // Pointer to store the result as a linked list

	if ((check_digit(argv[1])) == FAILURE) // Check if the first input is a valid number
	{
		printf("For help: \n./apc.exe num1 (+, -, x, /) num2\n");
		return 0;
	}
	if ((check_oper(argv[2][0])) == FAILURE) // Check if the operator is valid
	{
		printf("For help: \n./apc.exe num1 (+, -, x, /) num2\n");
		return 0;
	}
	if ((check_digit(argv[3])) == FAILURE) // Check if the second input is a valid number
	{
		printf("For help: \n./apc.exe num1 (+, -, x, /) num2\n");
		return 0;
	}
	Store_data(&data1, argv[1], &flag1); // Store the first number in data1 and set its sign flag
	Store_data(&data2, argv[3], &flag2); // Store the second number in data2 and set its sign flag

	if (argv[2][0] == '+') // Check if the operator is addition
	{
		if (flag1 == flag2) // If both numbers have the same sign
		{
			Addition(data1, data2, &res); // Perform addition
			if (flag1 == 1)				  // If the numbers are negative
			{
				printf("-"); // Print the negative sign
			}
		}
		else // If the numbers have different signs
		{
			if (check_value(data1, data2)) // Check which number is greater
			{
				if ((Subtraction(data2, data1, &res)) == FAILURE) // Perform subtraction (data2 - data1)
				{
					printf("Subtraction is not completed\n");
					return 0;
				}
				if (flag2 == 1) // If the second number is negative
				{
					printf("-");
				}
			}
			else
			{
				if ((Subtraction(data1, data2, &res)) == FAILURE) // Perform subtraction (data1 - data2)
				{
					printf("Subtraction is not completed\n");
					return 0;
				}
				if (flag1 == 1) // If the first number is negative
				{
					printf("-");
				}
			}
		}
	}
	else if (argv[2][0] == '-') // Check if the operator is subtraction
	{
		if (flag1 == flag2) // If both numbers have the same sign
		{
			if (check_value(data1, data2) == 1) // Check which number is greater
			{
				if ((Subtraction(data2, data1, &res)) == FAILURE) // Perform subtraction (data2 - data1)
				{
					printf("Subtraction is not completed\n");
					return 0;
				}
				if (flag1 == 0) // If the numbers are positive
				{
					printf("-");
				}
			}
			else
			{
				if ((Subtraction(data1, data2, &res)) == FAILURE) // Perform subtraction (data1 - data2)
				{
					printf("Subtraction is not completed\n");
					return 0;
				}
				if (flag1 == 1) // If the first number is negative
				{
					printf("-");
				}
			}
		}
		else // If the numbers have different signs
		{
			Addition(data1, data2, &res); // Perform addition
			if (flag1 == 1)				  // If the first number is negative
			{
				printf("-");
			}
		}
	}
	else if (argv[2][0] == 'x') // Check if the operator is multiplication
	{
		if (flag1 != flag2) // If the numbers have different signs
		{
			printf("-"); // Print the negative sign
		}
		Multi(data1, data2, &res); // Perform multiplication
	}
	else if (argv[2][0] == '/') // Check if the operator is division
	{
		if (flag1 != flag2) // If the numbers have different signs
		{
			printf("-"); // Print the negative sign
		}
		division(data1, data2, &res); // Perform division
	}
	Print_res(res); // Print the result
}
