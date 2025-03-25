#include "Apc.h" // Include the header file for necessary declarations

int copy_node(D_list **temp1, D_list *data1) // Function to copy nodes from one doubly linked list to another
{
	D_list *temp = *temp1; // Initialize temp to point to the head of the destination list
	while (data1) // Loop through each node in the source list
	{
		D_list *new = malloc(sizeof(D_list)); // Allocate memory for a new node
		if (new == NULL) // Check if memory allocation failed
		{
			return FAILURE; // Return failure if memory allocation fails
		}
		new->data = data1->data; // Copy data from the source node to the new node
		new->next = NULL; // Set the next pointer of the new node to NULL
		if ((*temp1 == NULL)) // Check if the destination list is empty
		{
			new->prev = NULL; // Set the previous pointer of the new node to NULL
			(*temp1) = new; // Set the head of the destination list to the new node
			temp = new; // Update temp to point to the new node
		}
		else // If the destination list is not empty
		{
			new->prev = temp; // Set the previous pointer of the new node to the current last node
			temp->next = new; // Link the current last node to the new node
			temp = new; // Update temp to point to the new node
		}
		data1 = data1->next; // Move to the next node in the source list
	}
}
