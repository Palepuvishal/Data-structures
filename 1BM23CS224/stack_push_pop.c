#include<stdio.h>


void push(int ele,int stack[],int *top,int n){
    if(*top == n-1){
        printf(" OVERFLOW \n");
    }
    else{
        (*top)++;
        stack[*top] = ele;
        printf("%d has been pushed \n",ele);
    }
}

void pop(int stack[],int *top){
    if((*top) == -1){
        printf(" UNDERFLOW \n");
    }
    else{
        int popped = stack[*top];
        (*top)--;
        printf("%d has been popped \n",popped);
    }
}

void display(int stack[],int *top){
    if((*top) == -1){
        printf("the stack is empty \n");
    }
    else{
        for(int i=0;i<=*top;i++){
            printf("%d \n",stack[i]);
        }
    }
}

int main(){
    int n = 5;
    int top = -1;
    int stack[n];
    push(10,stack,&top,n);
    push(15,stack,&top,n);
    push(25,stack,&top,n);
    push(30,stack,&top,n);
    display(stack,&top);
    pop(stack,&top);
    pop(stack,&top);
    display(stack,&top);
}