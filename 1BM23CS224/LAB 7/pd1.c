#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int value) {
    Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

Node *concat(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

Node *sort(Node *head) {
    Node *temp, *current;
    int t;
    current = head;
    while (current != NULL) {
        temp = head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

Node *reverse(Node *head) {
    Node *prev = NULL, *temp, *next;
    temp = head;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

void displayLinkedList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayLinkedLists(Node *head1, Node *head2) {
    printf("Linked List 1: ");
    displayLinkedList(head1);
    printf("Linked List 2: ");
    displayLinkedList(head2);
}

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;
    int choice, value;

    // User inputs five elements into each list directly in main
    printf("Enter 5 elements for Linked List 1:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        list1 = insertAtBeginning(list1, value);
    }

    printf("Enter 5 elements for Linked List 2:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        list2 = insertAtBeginning(list2, value);
    }

    // Display initial lists
    printf("Initial Linked Lists:\n");
    displayLinkedLists(list1, list2);

    // Display menu for operations
    do {
        printf("\nChoose an operation:\n");
        printf("1. Sort\n");
        printf("2. Reverse\n");
        printf("3. Concatenate\n");
        printf("4. Display Linked Lists\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list1 = sort(list1);
                list2 = sort(list2);
                printf("Sorted Linked Lists:\n");
                displayLinkedLists(list1, list2);
                break;
            case 2:
                list1 = reverse(list1);
                list2 = reverse(list2);
                printf("Reversed Linked Lists:\n");
                displayLinkedLists(list1, list2);
                break;
            case 3:
                list1 = concat(list1, list2);
                printf("Concatenated Linked List:\n");
                displayLinkedList(list1);
                break;
            case 4:
                printf("Current Linked Lists:\n");
                displayLinkedLists(list1, list2);
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

