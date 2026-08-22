#include <stdlib.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->stack = (int*)malloc(sizeof(int) * 30000);
    obj->minStack = (int*)malloc(sizeof(int) * 30000);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0)
        obj->minStack[obj->top] = val;
    else
        obj->minStack[obj->top] =
            (val < obj->minStack[obj->top - 1]) ? val : obj->minStack[obj->top - 1];
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
