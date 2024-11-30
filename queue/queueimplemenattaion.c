#include <stdio.h>
#include <stdlib.h>

// Creating anode
struct node {
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->link = temp;
    rear = temp;
}

void dequeue() {
    struct node *temp = front;
    if (front == NULL) {
        // Underflow error
        return;
    }
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->link;
    }
    free(temp);
}

int peek() {
    if (front == NULL) {
        printf("Empty state\n");
    }
    return front->data;
}

void print() {
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int top;
    enqueue(2);
    print();

    enqueue(8);
    print();

    dequeue();
    print();

    top = peek();
    printf("%d\n", top);

    return 0;
}
