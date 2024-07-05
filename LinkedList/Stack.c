#include "LinkedList.h"

// Init stack
Stack *createStack(size_t capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(stack));
    if (!stack)
        return NULL;

    stack->list = create_list();
    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}
// push
Stack *push_stack(Stack *st, void *data)
{
    if (st->size == st->capacity)
        return (printf("Stackoverflow\n"), st);

    if (!st)
        return NULL;

    prependNode(st->list, data);
    st->size++;

    return st;
}
// pop
Stack *pop_stack(Stack *st)
{
    if (st->size == 0)
        return NULL;
    if (!st)
        return NULL;
    delete_list(st->list, 0);
    st->size--;
    return st;
}

void *peek_stack(Stack *st) {
    printf("%d\n", *(int *) st->list->tail->data);
    return (st->list->tail->data);
}
// peek
// clear Stack
// destroy stack