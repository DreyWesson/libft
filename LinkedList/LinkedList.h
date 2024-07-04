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

// Create LinkedList
LinkedList *create_list();
// Create Node func
Node *create_node(void *data);
// Append and prepend ton list
LinkedList *appendNode(LinkedList *head, void *data);
LinkedList *appendNodeTr(LinkedList *head, void *data);
LinkedList *prependNode(LinkedList *list, void *data);
// PrintList
void printList(LinkedList *list);
// Clear list
void clearList(LinkedList *list);
// Reverse List
LinkedList *reverse(LinkedList *list);
// Insert to list
LinkedList *insert(LinkedList *list, void *data, size_t pos);
// delete one from list
LinkedList *delete_list(LinkedList *list, size_t pos);
// CREATE A STACK and QUEUE

// merge two halves
LinkedList *merge_list(LinkedList *list1, LinkedList *list2);
LinkedList *merge(LinkedList *list1, LinkedList *list2);
LinkedList *mergeSort(LinkedList *list);
// Split list into halves
// sort list
LinkedList *bubblesort_list(LinkedList *list1);


#endif