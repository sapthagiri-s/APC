#ifndef Apc_H // Include guard to prevent multiple inclusions of the header file
#define Apc_H 

#include <stdio.h> // Standard I/O library
#include <stdlib.h> // Standard library for memory allocation and process control
#include <string.h> // String manipulation functions
#include <ctype.h> // Character type functions

// Macro definitions for return status codes
#define SUCCESS 0 // Operation successful
#define FAILURE -1 // Operation failed
#define NOELEMENT -2 // No element found
#define EMPTYLIST -3 // List is empty
#define REPEATED -4 // Repeated element
#define FILE_EMPTY -5 // File is empty
#define NOT_PRESENT -6 // Element not present

// Structure definition for a singly linked list node
typedef struct node
{
    int data; // Data stored in the node
    struct node *link; // Pointer to the next node
} S_list;

// Structure definition for a doubly linked list node
typedef struct doubl 
{
    struct doubl *prev; // Pointer to the previous node
    int data; // Data stored in the node
    struct doubl *next; // Pointer to the next node
} D_list; // End of the doubly linked list structure definition

// Function prototypes
int check_digit(char *str); // Check if a string contains only digits
int check_oper(char opr); // Check if a character is a valid operator
int Store_data(D_list **data, char *str ,int *flag); // Store data in a doubly linked list
int Insert_at_first(D_list **data, int num); // Insert a node at the beginning of a doubly linked list
int Addition(D_list *head, D_list *head1, S_list **S_head); // Perform addition of two numbers represented as linked lists
int Store_in_single(S_list **S_head, int data); // Store data in a singly linked list
int check_value(D_list *data1 , D_list *data2); // Compare values of two doubly linked lists
int Subtraction(D_list *head, D_list *head1, S_list **S_head); // Perform subtraction of two numbers represented as linked lists
int Multi(D_list *data1, D_list *data2, S_list **res); // Perform multiplication of two numbers represented as linked lists
int division(D_list *data1 , D_list *data2 , S_list **res); // Perform division of two numbers represented as linked lists
int copy_node(D_list **temp1 , D_list *data1); // Copy a node from one doubly linked list to another
int Delete_list(D_list **head); // Delete all nodes in a doubly linked list
int copy_result_data(D_list **data1, S_list *res); // Copy result data from a singly linked list to a doubly linked list
int Delete_list_res(S_list **data); // Delete all nodes in a singly linked list
int Insert_at_last(S_list **res, int count); // Insert a node at the end of a singly linked list
int Print_res(S_list *res); // Print the result stored in a singly linked list

#endif // End of include guard
