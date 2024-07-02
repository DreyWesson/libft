#ifndef LINKEDLIST_H
# define LINKEDLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    void * data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

// Create LinkedList
LinkedList *create_list();
// Create Node func
Node *create_node(void *data);
// Append and prepend ton list
LinkedList *appendNode(LinkedList *head, void *data);
LinkedList *prependNode(LinkedList *list, void *data);
void printList(LinkedList *list);
// PrintList
// Reverse List
// Insert to list
// delete one from list
// Clear list
// CREATE A STACK and QUEUE

#endif