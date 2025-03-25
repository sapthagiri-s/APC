# Arbitrary Precision Calculator (APC)

## Overview

The Arbitrary Precision Calculator (APC) is a C-based program designed to perform arithmetic operations (addition, subtraction, multiplication, and division) on arbitrarily large numbers. The numbers are represented using linked lists to handle their size efficiently.

## Features

- **Addition**: Adds two large numbers.
- **Subtraction**: Subtracts one large number from another.
- **Multiplication**: Multiplies two large numbers.
- **Division**: Divides one large number by another.
- **Sign Handling**: Supports positive and negative numbers.
- **Efficient Storage**: Uses doubly and singly linked lists to store numbers and results.

## File Structure

- **Apc.h**: Header file containing structure definitions, macros, and function prototypes.
- **Check_digit.c**: Validates input strings and operators.
- **Addition.c**: Implements addition of two large numbers.
- **Subtraction.c**: Implements subtraction of two large numbers.
- **Multi.c**: Implements multiplication of two large numbers.
- **Division.c**: Implements division of two large numbers.
- **Store_data.c**: Converts input strings into linked list representations.
- **Copy_node.c**: Copies nodes between linked lists.
- **Copy_result.c**: Copies results from singly linked lists to doubly linked lists.
- **Delete_list.c**: Deletes all nodes in linked lists.
- **Insert_at_first.c**: Inserts a node at the beginning of a doubly linked list.
- **Insert_at_last.c**: Inserts a node at the end of a singly linked list.
- **Print.c**: Prints the result stored in a singly linked list.
- **main.c**: Entry point of the program, handles input and calls appropriate functions.

## Usage

1. Compile the program using `make`:
   ```bash
   make
   ```

2. Run the program with the following arguments:
   ```bash
   ./apc.exe <number1> <operator> <number2>
   ```
   - `<number1>`: The first large number (e.g., `12345678901234567890`).
   - `<operator>`: The arithmetic operator (`+`, `-`, `x`, `/`).
   - `<number2>`: The second large number (e.g., `98765432109876543210`).

3. Example:
   ```bash
   ./apc.exe 12345678901234567890 + 98765432109876543210
   ```

## Notes

- The program assumes valid input. Ensure the numbers and operators are correctly formatted.
- Division by zero is not handled and will result in undefined behavior.

## License

This project is open-source and available for educational purposes.
