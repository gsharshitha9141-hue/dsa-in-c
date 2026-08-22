#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *inStack;
    int *outStack;
    int inTop;
    int outTop;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->inStack = (int*)malloc(sizeof(int) * 30000);
    obj->outStack = (int*)malloc(sizeof(int) * 30000);
    obj->inTop = -1;
    obj->outTop = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inStack[++obj->inTop] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->outTop == -1) {
        while (obj->inTop != -1) {
            obj->outStack[++obj->outTop] = obj->inStack[obj->inTop--];
        }
    }
    return obj->outStack[obj->outTop--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outTop == -1) {
        while (obj->inTop != -1) {
            obj->outStack[++obj->outTop] = obj->inStack[obj->inTop--];
        }
    }
    return obj->outStack[obj->outTop];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->inTop == -1 && obj->outTop == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->inStack);
    free(obj->outStack);
    free(obj);
}
