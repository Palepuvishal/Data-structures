


typedef struct {
    int stack[1000];
    int helper[1000];
    int s;
    int h;
    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->s=0;
    queue->h=0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack[obj->s++] = x;
}

int myQueuePop(MyQueue* obj) {
    while(obj->s>0){
        obj->helper[obj->h++] = obj->stack[--obj->s];
    }
    int popped = obj->helper[--obj->h];
    while(obj->h>0){
        obj->stack[obj->s++] = obj->helper[--obj->h];
    }
    return popped;
}

int myQueuePeek(MyQueue* obj) {
    while(obj->s>0){
        obj->helper[obj->h++] = obj->stack[--obj->s];
    }
    int popped = obj->helper[--obj->h];
    obj->h++;
    while(obj->h>0){
        obj->stack[obj->s++] = obj->helper[--obj->h];
    }
    return popped;
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->s==0) return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/