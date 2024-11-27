#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

struct Node* insertNode(struct Node* root,int val){
    if(root==NULL) return createNode(val);
    if(val < root->val) {
        root->left = insertNode(root->left,val);
    }
    else root->right = insertNode(root->right,val);
    return root;
};

void postorder(struct Node* root){
    if(root!=NULL){
            postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
    }



}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root==NULL) return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}



int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert a node into the binary tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Inorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal:\n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal:\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
