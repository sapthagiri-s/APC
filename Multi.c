#include "Apc.h" // Include the header file containing necessary declarations

int Multi(D_list *data1, D_list *data2, S_list **res) // Function to multiply two linked lists
{
	int mult, carry = 0, count = 1, i = 1; // Initialize variables for multiplication, carry, count, and loop index
	D_list *temp = data1; // Pointer to traverse the first linked list
	D_list *temp1 = data2; // Pointer to traverse the second linked list

	// Move to the last node of both linked lists
	while ((temp && temp->next) || (temp1 && temp1->next)) 
	{
		if (temp != NULL && temp->next != NULL) // Move to the next node in the first list if not NULL
			temp = temp->next;
		if (temp1 != NULL && temp1->next != NULL) // Move to the next node in the second list if not NULL
			temp1 = temp1->next;
	}

	D_list *res1 = NULL, *res2 = NULL; // Initialize result lists for intermediate and final results

	// Loop through the second list from the last node
	while (temp1)
	{
		D_list *prev = temp; // Pointer to traverse the first list
		carry = 0; // Reset carry for each digit multiplication

		// Add leading zeros for intermediate results based on the position
		for (i = 1; i < count; i++) 
		{
			Insert_at_first(&res1, 0); // Insert 0 at the beginning of the intermediate result list
		}

		// Multiply each digit of the first list with the current digit of the second list
		while (prev)
		{
			mult = (prev->data * temp1->data) + carry; // Multiply digits and add carry
			carry = mult / 10000; // Calculate new carry
			mult = (mult % 10000); // Get the remainder as the current digit
			Insert_at_first(&res1, mult); // Insert the result at the beginning of the intermediate result list
			prev = prev->prev; // Move to the previous node in the first list
		}

		// If there's any carry left, insert it at the beginning
		if (carry != 0)
		{
			Insert_at_first(&res1, carry); // Insert carry at the beginning
			carry = 0; // Reset carry
		}

		// Add the intermediate result to the final result
		Addition(res1, res2, res); 
		temp1 = temp1->prev; // Move to the previous node in the second list
		count++; // Increment the position count
	}
}
