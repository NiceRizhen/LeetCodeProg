typedef struct 
{
    int *data;
    int top;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) 
{
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->data = (int *)malloc(maxSize * sizeof(int));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int x) 
{
    obj->data[++(obj->top)] = x;
}

void minStackPop(MinStack* obj)
{
    (obj->top)--;
}

int minStackTop(MinStack* obj)
{
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj)
{
    int size = obj->top;
    int i;
    int min = INT_MAX;
    for(i = 0; i <= size; i++)
    {
        if(obj->data[i] < min) min = obj->data[i];
    }
    
    return min;
}

void minStackFree(MinStack* obj)
{
    free(obj->data);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */