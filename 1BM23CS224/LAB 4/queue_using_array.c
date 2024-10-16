#include<stdio.h>
#include<stdbool.h>
#define MAX 5

void add(int arr[],int *front,int *rear,int val){
    if((*rear)==MAX-1){
        printf("OverFlow\n");
    }
    else{
        if((*front)==-1 && (*rear)==-1){
            (*front)++;
        }
        (*rear)++;
        arr[*rear] = val;
        printf("%d has been added\n",val);
    }
}

void delete1(int arr[],int *front,int *rear){
    if((*front)==-1 || (*front)>(*rear)){
        printf("UnderFlow\n");
    }
    else{
        int del = arr[*front];
        (*front)++;
        printf("%d has been deleted\n",del);
    }
}

void display(int arr[],int *front,int *rear){
    if((*front)==-1 || (*front)>(*rear)){
        printf("the queue is empty\n");
    }
    else{
        for(int i=(*front);i<=(*rear);i++){
            printf("%d  ",arr[i]);
        }
        printf("\n");
    }
}

int main(){
    int arr[MAX];
    int f = -1,r = -1;
    int n;
    printf("Enter 1 to add\n");
    printf("Enter 2 to delete\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");
    bool iswork = true;
    while(iswork){
        printf("Enter the  n \n");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the number\n");
            int a;
            scanf("%d",&a);
            add(arr,&f,&r,a);
        }
        else if(n==2){
            delete1(arr,&f,&r);
        }
        else if(n==3){
            display(arr,&f,&r);
        }
        else if(n==4){
            iswork = false;
        }
    }
    return 0;
    
}