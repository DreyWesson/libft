#include "LinkedList.h"

Node *create_node(void *data)
{
    Node *new_node = (Node *)calloc(sizeof(Node), 1);
    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

LinkedList *create_list()
{
    LinkedList *new_list = (LinkedList *)calloc(sizeof(LinkedList), 1);
    if (!new_list)
        return NULL;
    new_list->head = NULL;

    return new_list;
}

LinkedList *appendNode(LinkedList *list, void *data)
{
    if (!list) {
        list = create_list();
        if (!list)
            return NULL;
    }

    Node *new_node = create_node(data);
    if (!new_node)
        return NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        Node *tmp = list->head;
        while ( tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    return (list);
}

LinkedList *prependNode(LinkedList *list, void *data)
{
    if (!list) {
        list = create_list();
        if (!list)
            return NULL;
    }

    Node *new_node = create_node(data);
    if (!new_node)
        return NULL;
    // new_node->next = list->head;
    list->head = new_node;
    return (list);
}

void printList(LinkedList *list) {
    if (!list)
        return ;
    Node *tmp = list->head;

    while (tmp)
    {
        printf("%d\n", *(int *)tmp->data);
        tmp = tmp->next;
    }
    
}