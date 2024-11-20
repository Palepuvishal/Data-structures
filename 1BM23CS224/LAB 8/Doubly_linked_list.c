#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

void insertFront(struct Node** head, int data) {

      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

      newNode->data = data;
      newNode->next = (*head);
      newNode->prev = NULL;
      if ((*head) != NULL)
        (*head)->prev = newNode;
      (*head) = newNode;
    }

void insertLeftToNode(struct Node** head,int val,int data){
    struct Node *temp = *head;
    int i = 1;
    while(temp!=NULL && temp->data!=val){
        temp= temp->next;
        i++;
    }
    if(temp==NULL){
         printf("Given value is not present \n");
         return;
    }
   /* struct Node *temp = *head;
    for(int j = 1;j<i;j++){
        temp = temp->next;
    }*/

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev = newnode;
    newnode->prev->next = newnode;

}

void deletewithvlaue(struct Node** head,int val){
        struct Node *temp = *head;
    int i = 1;
    while(temp!=NULL && temp->data!=val){
        temp= temp->next;
        i++;
    }
    if(temp==NULL){
         printf("Given value is not present \n");
         return;
    }
    /*
    struct Node *temp = *head;
    for(int j = 1;j<i;j++){
        temp = temp->next;
    }*/

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL; // Initialize the doubly linked list as empty
    int choice, data, value;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Front\n");
        printf("2. insertLeftToNode\n");
        printf("3. deletewithvlaue\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(&head, data);
                printf("Node inserted at the front.\n");
                break;

            case 2:
                printf("Enter the value to of a node: ");
                scanf("%d", &value);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertLeftToNode(&head, value,data);
                break;

            case 3:
                printf("Enter the value of a node: ");
                scanf("%d", &value);
                deletewithvlaue(&head, value);
                break;

            case 4:
                printf("The list is: ");
                displayList(head);
                break;

            case 5:
                printf("Exiting the program.\n");
                // Free all remaining nodes in the list before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
