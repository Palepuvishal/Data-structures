#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

struct node *head = NULL;

void enqueue(int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is Empty. Unable to perform dequeue.\n");
    } else {
        temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        printf("Dequeued element = %d\n", temp->data);
        free(temp);
    }
}

void printQueue() {
    struct node *temp = front;
    printf("Queue: ");
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void push(int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop() {
    struct node *temp;
    if (head == NULL) {
        printf("Stack is Empty.\n");
    } else {
        printf("Popped element = %d\n", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printStack() {
    struct node *temp = head;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    do {
        printf("\nSelect an operation:\n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Push \n");
        printf("4. Pop \n");
        printf("5.  Queue\n");
        printf("6.  Stack\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 4:
                pop();
                break;
            case 5:
                printQueue();
                break;
            case 6:
                printStack();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
