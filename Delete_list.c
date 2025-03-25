#include "Apc.h" // Include the header file "Apc.h" for necessary declarations

int Delete_list(D_list **head) // Function to delete all nodes in a doubly linked list
{
    D_list *temp; // Temporary pointer to hold the current node
    while ((*head)) // Loop until the head pointer becomes NULL
    {
        temp = (*head); // Store the current head node in temp
        (*head) = temp->next; // Move the head pointer to the next node
        free(temp); // Free the memory of the current node
    }
    return SUCCESS; // Return SUCCESS after deletion
}

int Delete_list_res(S_list **data) // Function to delete all nodes in a singly linked list
{
    S_list *temp; // Temporary pointer to hold the current node
    while ((*data)) // Loop until the data pointer becomes NULL
    {
        temp = (*data); // Store the current data node in temp
        (*data) = temp->link; // Move the data pointer to the next node
        free(temp); // Free the memory of the current node
    }
    return SUCCESS; // Return SUCCESS after deletion
}
