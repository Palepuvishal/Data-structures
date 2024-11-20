#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* middleNode(struct ListNode* head) {
    int n = 0;
    struct ListNode* temp = head;

    while (temp != NULL) {
        temp = temp->next;
        n++;
    }

    struct ListNode* cur = head;
    for (int i = 1; i <= n / 2; i++) {
        cur = cur->next;
    }

    return cur;
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void append(struct ListNode** head, int value) {
    struct ListNode* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct ListNode* head = NULL;
    int value;
    char choice;

    do {
        printf("Enter a value to add to the linked list: ");
        scanf("%d", &value);

        append(&head, value);

        printf("Do you want to add another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');


    printf("The linked list is: ");
    printList(head);


    struct ListNode* middle = middleNode(head);
    printf("The middle node value is: %d\n", middle->val);

    return 0;
}
