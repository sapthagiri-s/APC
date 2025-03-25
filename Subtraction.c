#include "Apc.h" // Include the header file for function declarations and definitions

int Subtraction(D_list *head, D_list *head1, S_list **S_head) // Function to perform subtraction of two numbers represented as doubly linked lists
{
	int carry = 0, sub = 0, num1 = 0, num2 = 0; // Initialize variables for carry, subtraction result, and digits
	D_list *temp = head; // Pointer to traverse the first linked list
	D_list *temp1 = head1; // Pointer to traverse the second linked list
	while ((temp && temp->next) || (temp1 && temp1->next)) // Traverse to the end of both linked lists
	{
		if (temp != NULL && temp->next != NULL) // Move to the next node in the first list if it exists
			temp = temp->next;
		if (temp1 != NULL && temp1->next != NULL) // Move to the next node in the second list if it exists
			temp1 = temp1->next;
	}
	while (temp != NULL || temp1 != NULL) // Traverse both lists from the end to the beginning
	{
		if (temp != NULL) // If the current node in the first list exists
		{
			num1 = temp->data; // Get the data from the current node of the first list
			temp = temp->prev; // Move to the previous node in the first list
		}
		else
			num1 = 0; // If the first list is exhausted, set num1 to 0
		if (temp1 != NULL) // If the current node in the second list exists
		{
			num2 = temp1->data; // Get the data from the current node of the second list
			temp1 = temp1->prev; // Move to the previous node in the second list
		}
		else
			num2 = 0; // If the second list is exhausted, set num2 to 0
		num1 = num1 - carry; // Subtract the carry from the current digit of the first number
		if (num1 >= num2) // If the current digit of the first number is greater than or equal to the second
		{
			carry = 0; // No carry is needed
			sub = num1 - num2; // Perform the subtraction
			Store_in_single(S_head, sub); // Store the result in the single linked list
		}
		else // If the current digit of the first number is less than the second
		{
			carry = 1; // Set carry to 1 for the next iteration
			sub = (num1 + 10000) - num2; // Perform the subtraction with borrowing
			Store_in_single(S_head, sub); // Store the result in the single linked list
		}
	}
	return SUCCESS; // Return success status
}
