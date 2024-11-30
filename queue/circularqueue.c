#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

// Global variables
int a[MAX_SIZE]; // Array to store the queue elements
int front = -1;  // Points to the front of the queue
int rear = -1;   // Points to the rear of the queue

// Function to add an element to the queue
void enqueue(int x) {
    // Case 1: Queue is empty
    if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    // Case 2: Queue is full (circular condition)
    else if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full\n");
        return;
    }
    // Case 3: Normal insertion
    else {
        rear = (rear + 1) % MAX_SIZE;
    }
    a[rear] = x; // Insert the new element
}

// Function to remove an element from the queue
void dequeue() {
    // Case 1: Queue is empty
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    // Case 2: Single element left in the queue
    else if (front == rear) {
        front = rear = -1;
    }
    // Case 3: Normal removal
    else {
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to get the front element of the queue
int Peek() {
    if (front == -1) { // If queue is empty, return -1
        return -1;
    }
    return a[front]; // Return the front element
}

// Function to print all elements in the queue
void Print() {
    if (front == -1) { // Handle empty queue
        printf("Queue is empty\n");
        return;
    }
    // Calculate the number of elements in the queue
    int count = ((rear + MAX_SIZE - front) % MAX_SIZE) + 1;
    for (int i = 0; i < count; i++) {
        // Print elements in a circular manner
        printf("%d ", a[(front + i) % MAX_SIZE]);
    }
    printf("\n");
}

// Main function to demonstrate the circular queue operations
int main(void) {
    enqueue(5); // Insert 5 into the queue
    printf("\nFirst insertion in circular Queue\n");
    Print();

    enqueue(7); // Insert 7 into the queue
    printf("\nSecond insertion in circular Queue\n");
    Print();

    enqueue(-3); // Insert -3 into the queue
    printf("\nThird insertion in circular Queue\n");
    Print();

    enqueue(9); // Insert 9 into the queue
    printf("\nFourth insertion in circular Queue\n");
    Print();

    dequeue(); // Remove the front element
    printf("\nCircular Queue after first deletion\n");
    Print();

    dequeue(); // Remove the front element again
    printf("\nCircular Queue after second deletion\n");
    Print();

    enqueue(14); // Insert 14 into the queue
    printf("\nInsertion in circular Queue\n");
    Print();

    
    return 0;
}
