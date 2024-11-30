#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Define the maximum size of the stack

char stack[MAX]; // Stack to hold operators and parentheses
int top = -1;    // Top of the stack

// Function to push an element onto the stack
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    char postfix[MAX]; // Array to hold the postfix expression
    int i = 0, j = 0;  // i for infix, j for postfix

    while (infix[i] != '\0') {
        char ch = infix[i];

        // Case 1: If the symbol is an operand
        if (isalnum(ch)) {
            postfix[j++] = ch; // Append to postfix expression
        }
        // Case 2: If the symbol is a left parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // Case 3: If the symbol is a right parenthesis
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop and append all operators
            }
            pop(); // Discard the left parenthesis
        }
        // Case 4: If the symbol is an operator
        else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop(); // Pop operators with higher or equal precedence
            }
            push(ch); // Push the current operator onto the stack
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix); // Convert to postfix
    return 0;
}
