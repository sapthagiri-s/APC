#include "Apc.h" // Include the header file containing necessary declarations

int Insert_at_last(S_list **res, int count) // Function to insert a node at the end of the linked list
{
    S_list *temp = *res; // Create a temporary pointer to traverse the list
    S_list *new = malloc(sizeof(S_list)); // Allocate memory for the new node
    new->data = count; // Assign the data to the new node
    new->link = NULL; // Set the link of the new node to NULL
    if (temp == NULL) // Check if the list is empty
    {
        (*res) = new; // If empty, set the new node as the head of the list
    }
    else
    {
        while (temp->link != NULL) // Traverse the list to find the last node
        {
            temp = temp->link; // Move to the next node
        }
        temp->link = new; // Link the last node to the new node
    }
}
