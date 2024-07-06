#include "LinkedList.h"

// Init stack
Stack *createStack(size_t capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
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

// peek
void *peek_stack(Stack *st) {
    return (st && st->list && st->list->head)
        ? (st->list->head->data)
        : NULL;
}

// clear Stack
void clear_stack(Stack *st) {
    if (!st) return;
    if (st->list)
        clearList(st->list);
    free(st->list);
}

// destroy stack
void destroy_stack(Stack *st) {
    if (!st) return;
    if (st->list) {
        clear_stack(st);
    }

    free(st);
}

int isEmpty(Stack *st) {
    if (!st || st->size == 0) return 1;
    return 0;
}

char *strchr_(const char *s, int c) {
    if (!s)
        return NULL;

    while (*s !='\0') {
        if ((char)*s == (char)c)
            return (char *)(s);
        s++;
    }
    if ((char)*s == '\0')
        return (char *)s;
    return NULL;
}

int isMatched(Stack *st, char s) {
    char c = *(char *)peek_stack(st);
    return (s == '(')
        ?  (c != c + 1)
        : (c != c + 2);
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']') ||
           (open == '<' && close == '>');
}

void printListChar(LinkedList *list)
{
    if (!list) return;
    Node *tmp = list->head;
    while (tmp)
    {
        printf("%c\n", *(char *)tmp->data);
        tmp = tmp->next;
    }
}



int isMatchingParenthesis(char *str) {
    if (!str)
        return 0;
    size_t len = strlen(str);
    Stack *st = createStack(len);

    char * openers = "(<{[";
    char * closers = ")>}]";

    while (*str != '\0')
    {
        if (strchr(openers, *str)) push_stack(st, str);
        if (strchr(closers, *str)) {
            if (isEmpty(st)) {
                destroy_stack(st);
                return (0);
            }
            if (isMatched(st, *str)) pop_stack(st);
        }
        str++;
    }
    int empty = isEmpty(st);
        destroy_stack(st);
    
    return (!empty) ? 0:  1;
}
