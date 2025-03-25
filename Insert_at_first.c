#include "Apc.h" // Include the header file containing necessary declarations

int Insert_at_first(D_list **head, int data) // Function to insert a node at the beginning of a doubly linked list
{
    D_list *new = malloc(sizeof(D_list)); // Allocate memory for a new node
    if (new == NULL) // Check if memory allocation failed
        return FAILURE; // Return failure if memory allocation failed
    new->data = data; // Assign the data to the new node
    new->next = NULL; // Initialize the next pointer of the new node to NULL
    new->prev = NULL; // Initialize the previous pointer of the new node to NULL
    if ((*head) == NULL) // Check if the list is empty
    {
        (*head) = new; // Set the new node as the head of the list
        return SUCCESS; // Return success
    }
    new->next = (*head); // Point the next of the new node to the current head
    (*head)->prev = new; // Update the previous pointer of the current head to the new node
    (*head) = new; // Update the head to the new node
    return SUCCESS; // Return success
}
