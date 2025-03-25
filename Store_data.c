#include "Apc.h" // Include the header file "Apc.h"

int Store_data(D_list **data, char *str, int *flag) // Function to store data into a linked list
{
    int i = 0, j = 0, num; // Initialize variables for iteration and number storage
    char temp[5]; // Temporary array to hold a substring of 4 characters
    int len = strlen(str); // Get the length of the input string
    int len1 = len - 1; // Get the index of the last character in the string
    if (str[0] == '+' || str[0] == '-') // Check if the string starts with '+' or '-'
    {
        *flag = 1; // Set the flag to 1 if the string has a sign
    }
    while (i < ((len - *flag) / 4)) // Loop to process chunks of 4 characters
    {
        for (j = 0; j < 4; j++) // Loop to copy 4 characters in reverse order
        {
            temp[3 - j] = str[len1--]; // Copy characters from the end of the string
        }
        num = atoi(temp); // Convert the 4-character substring to an integer
        Insert_at_first(data, num); // Insert the integer at the beginning of the linked list
        i++; // Increment the chunk counter
    }
    for (j = 0; j < (len - *flag) % 4; j++) // Loop to process the remaining characters
    {
        temp[j] = str[*flag + j]; // Copy the remaining characters into the temp array
    }
    temp[j] = '\0'; // Null-terminate the temp string
    num = atoi(temp); // Convert the remaining substring to an integer
    if (num != 0) // Check if the number is not zero
    {
        Insert_at_first(data, num); // Insert the number at the beginning of the linked list
    }
    if (*flag) // Check if the flag is set
    {
        if (str[0] == '-') // Check if the string starts with '-'
        {
            *flag = 1; // Set the flag to 1 for negative numbers
        }
        else
            *flag = 0; // Set the flag to 0 for positive numbers
    }
    return SUCCESS; // Return success status
}
