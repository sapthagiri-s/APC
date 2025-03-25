#include "Apc.h" // Include the header file "Apc.h"

int check_digit(char *str) // Function to check if a string contains valid digits
{
	int i = 0; // Initialize index variable
	while (str[i] != '\0') // Loop through the string until the null terminator is reached
	{
		if (i == 0) // Check the first character
		{
			if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) // Allow '+' or '-' or a digit
				; // Do nothing
			else
				return FAILURE; // Return FAILURE if the first character is invalid
		}
		else // Check subsequent characters
		{
			if (str[i] >= '0' && str[i] <= '9') // Allow only digits
				; // Do nothing
			else
				return FAILURE; // Return FAILURE if a non-digit is found
		}
		i++; // Move to the next character
	}
	return SUCCESS; // Return SUCCESS if all characters are valid
}

int check_oper(char opr) // Function to check if the operator is valid
{
	if (opr == '+' || opr == '-' || opr == 'x' || opr == '/') // Allow '+', '-', 'x', or '/'
		; // Do nothing
	else
		return FAILURE; // Return FAILURE if the operator is invalid
	return SUCCESS; // Return SUCCESS if the operator is valid
}

int check_value(D_list *data1, D_list *data2) // Function to compare two linked lists
{
	int count1 = 0, count2 = 0; // Initialize counters for both lists
	D_list *temp = data1, *temp1 = data2; // Temporary pointers for traversal
	while (temp || temp1) // Loop until both lists are fully traversed
	{
		if (temp) // If the first list is not null
		{
			temp = temp->next; // Move to the next node in the first list
			count1++; // Increment the counter for the first list
		}
		if (temp1) // If the second list is not null
		{
			temp1 = temp1->next; // Move to the next node in the second list
			count2++; // Increment the counter for the second list
		}
	}
	temp = data1; // Reset the pointer for the first list
	temp1 = data2; // Reset the pointer for the second list
	if (count1 == count2) // If both lists have the same length
	{
		while (temp) // Traverse the lists
		{
			if (temp->data > temp1->data) // If a node in the first list is greater
			{
				return 0; // Return 0
			}
			else if (temp->data < temp1->data) // If a node in the second list is greater
			{
				return 1; // Return 1
			}
			else // If the nodes are equal
			{
				temp = temp->next; // Move to the next node in the first list
				temp1 = temp1->next; // Move to the next node in the second list
			}
		}
		return 2; // Return 2 if all nodes are equal
	}
	else // If the lists have different lengths
	{
		if (count2 > count1) // If the second list is longer
		{
			return 1; // Return 1
		}
		else // If the first list is longer
		{
			return 0; // Return 0
		}
	}
}
