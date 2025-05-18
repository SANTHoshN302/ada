/* LEETCODE 1 */
/*Leetcode exercises on Stacks, Queues, Circular Queues,
Priority Queues*/
/* implementing Queue using stacks */

typedef struct {
    int *arr;
    int top;
    unsigned capacity;
    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 50;
    queue->top = -1;
    queue->arr = (int*)malloc(50* sizeof(int));

    return queue;
}

void myQueuePush(MyQueue* obj, int x) {

    obj->arr[++obj->top] = x;
}

int myQueuePop(MyQueue* obj) {

    if(obj->top == -1)
    {
        return -1;
    }

     int data = obj->arr[0];
    for (int i = 0; i < obj->top; i++) {
        obj->arr[i] = obj->arr[i + 1];
    }

    obj->top--;  
    return data;   
}

int myQueuePeek(MyQueue* obj) {

    if(obj->top != -1)
    { 
        return obj->arr[0];
    }
    return -1;
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}

/* Implementing stacks using Queue */

typedef struct {
    int idx;
    int size;
    int* stack;
} MyStack;


MyStack* myStackCreate() {
    MyStack* arr = calloc(1, sizeof(MyStack));
    arr->stack =  calloc(100, sizeof(MyStack));
    arr->size = 100;
    return arr;
}

void myStackPush(MyStack* obj, int x) {
    if (obj) {
        if (obj->idx >= obj->size) {
            obj->stack = realloc(obj->stack, obj->size + 100);
            obj->size += 100;
        }
        obj->stack[obj->idx++] = x;
    }    
}

int myStackPop(MyStack* obj) {
    if (obj) {
        if (obj->idx) {
            return obj->stack[--obj->idx];
        }
    }
    return 0;
}

int myStackTop(MyStack* obj) {
    if (obj) {
        if (obj->idx) {
            return obj->stack[obj->idx - 1];
        }
    }
    return 0;
}

bool myStackEmpty(MyStack* obj) {
    if (obj) {
        if (obj->idx) return false;
    }
    return true;
}

void myStackFree(MyStack* obj) {
    if (obj) {
        if (obj->stack) free(obj->stack);
        free(obj);
    }
}



