#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

typedef struct Stack {
    LinkedList *list;
    size_t capacity;
    size_t size;
    Node *top;
} Stack;

LinkedList *create_list();
Node *create_node(void *data);
LinkedList *appendNode(LinkedList *head, void *data);
LinkedList *appendNodeTr(LinkedList *head, void *data);
LinkedList *prependNode(LinkedList *list, void *data);
void printList(LinkedList *list);
void clearList(LinkedList *list);
void destroyList(LinkedList *list);
LinkedList *reverse(LinkedList *list);
LinkedList *insert(LinkedList *list, void *data, size_t pos);
LinkedList *delete_list(LinkedList *list, size_t pos);
LinkedList *merge(LinkedList *list1, LinkedList *list2);
LinkedList *mergeSort(LinkedList *list);
LinkedList *bubblesort_list(LinkedList *list1);
int safeInit(LinkedList **list);
Stack *push_stack(Stack *st, void *data);
Stack *pop_stack(Stack *st);
void *peek_stack(Stack *st);
void clear_stack(Stack *st);
void destroy_stack(Stack *st);
int isMatchingParenthesis(char *str);

Stack *createStack(size_t capacity);

#endif
