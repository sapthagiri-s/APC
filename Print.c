#include "Apc.h" // Include the header file "Apc.h" for necessary declarations

int Print_res(S_list *res) // Function to print the elements of a singly linked list
{
    S_list *temp2 = res; // Initialize a temporary pointer to traverse the list
    while (temp2) // Loop through the list until the end is reached
    {
        printf("%d", temp2->data); // Print the data of the current node
        temp2 = temp2->link; // Move to the next node in the list
    }
    printf("\n"); // Print a newline after printing all elements
}
