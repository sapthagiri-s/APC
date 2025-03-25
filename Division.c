#include "Apc.h" // Include the header file containing function declarations and definitions

int division(D_list *data1, D_list *data2, S_list **res) // Function to perform division of two linked lists
{
	int count = 0; // Initialize count to 0
	D_list *temp = NULL, *div_res = NULL; // Temporary pointers for intermediate results
	S_list *res1 = NULL; // Pointer for storing subtraction results
	D_list *value = malloc(sizeof(D_list)); // Allocate memory for a single node
	value->data = 1; // Set the data of the node to 1
	value->prev = NULL; // Initialize the previous pointer to NULL
	value->next = NULL; // Initialize the next pointer to NULL
	copy_node(&temp, data1); // Copy data1 into temp
	if (check_value(data2, temp)) // Check if data2 is less than or equal to temp
	{
		while (check_value(data2, temp)) // Loop while data2 is less than or equal to temp
		{
			count++; // Increment count
			Subtraction(temp, data2, &res1); // Subtract data2 from temp and store the result in res1
			Delete_list(&temp); // Delete the temp list
			copy_result_data(&temp, res1); // Copy the result from res1 to temp
			Delete_list_res(&res1); // Delete the res1 list
			if (count > 9999) // Check if count exceeds 9999
			{
				count = 0; // Reset count to 0
				Delete_list_res(res); // Delete the result list
				Addition(div_res, value, res); // Add value to div_res and store the result in res
				Delete_list(&div_res); // Delete the div_res list
				copy_result_data(&div_res, *res); // Copy the result from res to div_res
			}
		}
		Insert_at_last(res, count); // Insert the final count at the end of the result list
	}
	else // If data2 is greater than temp
	{
		*res = malloc(sizeof(S_list)); // Allocate memory for the result list
		if ((*res) == NULL) // Check if memory allocation failed
		{
			return FAILURE; // Return failure
		}
		(*res)->data = 0; // Set the result data to 0
		(*res)->link = NULL; // Set the result link to NULL
		return SUCCESS; // Return success
	}
}
