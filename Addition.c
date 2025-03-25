#include "Apc.h" // Include the header file "Apc.h"

int Addition(D_list *head, D_list *head1, S_list **S_head) // Function to add two doubly linked lists and store the result in a singly linked list
{
	int add = 0, num1 = 0, num2 = 0; // Initialize variables for addition and temporary storage
	D_list *temp = head; // Pointer to traverse the first doubly linked list
	D_list *temp1 = head1; // Pointer to traverse the second doubly linked list
	while ((temp && temp->next) || (temp1 && temp1->next)) // Traverse to the end of both doubly linked lists
	{
		if (temp != NULL && temp->next != NULL) // Move to the next node in the first doubly linked list
			temp = temp->next; // Update temp to the next node
		if (temp1 != NULL && temp1->next != NULL) // Move to the next node in the second doubly linked list
			temp1 = temp1->next; // Update temp1 to the next node
	}
	while (temp != NULL || temp1 != NULL) // Traverse both lists from the end to the beginning
	{
		if (temp != NULL) // If the current node in the first list is not NULL
		{
			num1 = temp->data; // Get the data from the current node of the first list
			temp = temp->prev; // Move to the previous node in the first list
		}
		else
			num1 = 0; // If the first list is exhausted, set num1 to 0
		if (temp1 != NULL) // If the current node in the second list is not NULL
		{
			num2 = temp1->data; // Get the data from the current node of the second list
			temp1 = temp1->prev; // Move to the previous node in the second list
		}
		else
			num2 = 0; // If the second list is exhausted, set num2 to 0
		add = num1 + num2 + add; // Add the two numbers and the carry
		Store_in_single(S_head, (add % 10000)); // Store the last 4 digits of the sum in the singly linked list
		if (add > 9999) // Check if there is a carry
		{
			add = 1; // Set carry to 1
		}
		else
		{
			add = 0; // Reset carry to 0
		}
	}
	if (add == 1) // If there is a remaining carry after the loop
		Store_in_single(S_head, 1); // Store the carry in the singly linked list
}

int Store_in_single(S_list **S_head, int data) // Function to store a number in the singly linked list
{
	S_list *new = malloc(sizeof(S_list)); // Allocate memory for a new node
	if (new == NULL) // Check if memory allocation failed
		return FAILURE; // Return failure if memory allocation failed
	new->data = data; // Set the data of the new node
	if ((*S_head) == NULL) // If the singly linked list is empty
	{
		new->link = NULL; // Set the link of the new node to NULL
		(*S_head) = new; // Set the head of the list to the new node
		return SUCCESS; // Return success
	}
	else // If the singly linked list is not empty
	{
		new->link = (*S_head); // Link the new node to the current head
		(*S_head) = new; // Update the head to the new node
		return SUCCESS; // Return success
	}
}
