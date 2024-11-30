#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Global variables for the stack
int top = -1;
char stack[MAX];

// Function prototypes
void push(char);
char pop();
int isEmpty();
int isFull();
int check_balanced(char *);
int match_char(char, char);

int main() {
    char expr[MAX];
    int balanced;

    // Input the algebraic expression
    printf("Enter the algebraic expression: ");
    gets(expr); // Use fgets instead of gets in modern code for safety.

    // Check if the expression is balanced
    balanced = check_balanced(expr);

    // Print the result
    if (balanced == 1) {
        printf("The expression is valid.");
    } else {
        printf("The expression is invalid.");
    }

    return 0;
}

// Function to check if the expression is balanced
int check_balanced(char *s) {
    char temp;

    // Traverse through the expression
    for (int i = 0; s[i] != '\0'; i++) {
        // If the character is an opening bracket, push it onto the stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        // If the character is a closing bracket
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            // Check if the stack is empty
            if (isEmpty()) {
                return 0; // Unmatched closing bracket
            }

            // Pop the top element and check for mismatch
            temp = pop();
            if (!match_char(temp, s[i])) {
                return 0; // Mismatched brackets
            }
        }
    }

    // After scanning all characters, the stack should be empty for a valid expression
    if (isEmpty()) {
        return 1; // Valid expression
    } else {
        return 0; // Unmatched opening brackets
    }
}

// Function to push an element onto the stack
void push(char c) {
    if (isFull()) {
        printf("Stack overflow. Cannot push '%c'\n", c);
        exit(1);
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack underflow. Cannot pop.\n");
        exit(1);
    }
    return stack[top--];
}

// Function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to check if the stack is full
int isFull() {
    return (top == MAX - 1);
}

// Function to check if the characters match
int match_char(char opening, char closing) {
    if (opening == '(' && closing == ')') return 1;
    if (opening == '{' && closing == '}') return 1;
    if (opening == '[' && closing == ']') return 1;
    return 0;
}
