#include "Apc.h" // Include the header file containing necessary declarations

int copy_result_data(D_list **data1, S_list *res) // Function to copy data from S_list to D_list
{
	D_list *temp1 = (*data1); // Initialize a temporary pointer to the head of D_list
	int count = 0; // Initialize a counter variable (unused in this code)
	
	while (res != NULL && res->data == 0) // Skip nodes in S_list with data equal to 0
	{
		res = res->link; // Move to the next node in S_list
	}
	
	while (res) // Iterate through the remaining nodes in S_list
	{
		D_list *new = malloc(sizeof(D_list)); // Allocate memory for a new D_list node
		if (new == NULL) // Check if memory allocation failed
		{
			return FAILURE; // Return FAILURE if memory allocation fails
		}
		new->data = res->data; // Copy data from the current S_list node to the new D_list node
		new->next = NULL; // Set the next pointer of the new node to NULL
		
		if ((*data1) == NULL) // Check if the D_list is empty
		{
			new->prev = NULL; // Set the previous pointer of the new node to NULL
			(*data1) = new; // Set the head of D_list to the new node
			temp1 = new; // Update the temporary pointer to the new node
		}
		else // If the D_list is not empty
		{
			new->prev = temp1; // Set the previous pointer of the new node to the last node
			temp1->next = new; // Link the last node to the new node
			temp1 = new; // Update the temporary pointer to the new node
		}
		res = res->link; // Move to the next node in S_list
	}
}
