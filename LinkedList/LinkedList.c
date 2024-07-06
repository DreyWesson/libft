#include "LinkedList.h"

Node *create_node(void *data)
{
    Node *new_node = (Node *)calloc(sizeof(Node), 1);
    if (!new_node) return NULL;

    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

LinkedList *create_list()
{
    LinkedList *new_list = (LinkedList *)calloc(sizeof(LinkedList), 1);
    if (!new_list) return NULL;

    new_list->head = new_list->tail = NULL;
    new_list->size = 0;

    return new_list;
}


int safeInit(LinkedList **list_ptr) {
    if (!list_ptr || !*list_ptr) {
        LinkedList *new_list = create_list();
        if (!new_list) return 0;
        *list_ptr = new_list;
    }
    return 1;
}


LinkedList *appendNode(LinkedList *list, void *data)
{
    Node *new_node = create_node(data);
    if (!new_node) return NULL;
    if (!list) {
        list = create_list();
        if (!list)return NULL;

        list->size = 1;
        list->head = list->tail = new_node;
    } else {
        if (list->head == NULL)
            list->head = new_node;
        else
            list->tail->next = new_node;

        list->tail = new_node;
        list->size += 1;

    }

    return (list);
}

LinkedList *appendNodeTr(LinkedList *list, void *data)
{
    if (!safeInit(&list)) return NULL;

    Node *new_node = create_node(data);
    if (!new_node) return NULL;

    list->tail = new_node;
    list->size += 1;

    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        Node *tmp = list->head;
        while (tmp && tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = new_node;
        list->tail = new_node;
    }


    return (list);
}

LinkedList *prependNode(LinkedList *list, void *data) {
    if (!list) return NULL;

    Node *new_node = create_node(data);
    if (!new_node) return NULL;

    new_node->next = list->head;
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }

    list->size += 1;

    return list;
}


// LinkedList *prependNode(LinkedList *list, void *data)
// {
//     Node *new_node = create_node(data);
//     if (!new_node) return NULL;

//     new_node->next = list->head;
//     list->head = new_node;
//     list->size += 1;

//     return list;
// }

void clearList(LinkedList *list)
{
    if (!list || !list->head) return;
    Node *tmp = list->head;
    Node *cache;
    while (tmp)
    {
        cache = tmp->next;
        free(tmp);
        tmp = cache;
    }

    list->head = list->tail = NULL;
    list->size = 0;
}

void destroyList(LinkedList *list)
{
    if (!list) return;

    if (list->head)
        clearList(list);

    free(list);
}

LinkedList *insert(LinkedList *list, void *data, size_t pos)
{
    if (!safeInit(&list)) return NULL;

    if (pos >= list->size)
        return appendNode(list, data);

    if (pos == 0)
        return prependNode(list, data);

    size_t pointer = 0;
    Node *tmp = list->head;
    Node *new_node = create_node(data);
    Node *rest_node = tmp->next;

    while (pointer < (pos - 1) && tmp != NULL)
    {
        tmp = tmp->next;
        pointer++;
    }
    if (!new_node) return NULL;

    tmp->next = new_node;
    new_node->next = rest_node;
    list->size += 1;

    return list;
}

LinkedList *delete_list(LinkedList *list, size_t pos)
{
    if (!list || !list->head) return NULL;

    if (pos >= list->size) return list;

    Node *to_delete;
    if (pos == 0)
    {

        to_delete = list->head;
        list->head = list->head->next;
        if (list->size == 1)
            list->tail = NULL;
        free(to_delete);
    }
    else
    {
        size_t pointer = 0;
        Node *itr = list->head;

        while (pointer < (pos - 1) && itr->next != NULL)
        {
            itr = itr->next;
            pointer++;
        }

        to_delete = itr->next;
        itr->next = itr->next->next;

        if (to_delete == list->tail)
            list->tail = itr;

        free(to_delete);
    }

    list->size--;
    return list;
}

void printList(LinkedList *list)
{
    if (!list) return;
    Node *tmp = list->head;
    while (tmp)
    {
        printf("%d\n", *(int *)tmp->data);
        tmp = tmp->next;
    }
}

LinkedList *reverse(LinkedList *list)
{
    Node *prev = NULL;
    Node *current = list->head;
    Node *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
    return list;
}

LinkedList *merge_list(LinkedList *list1, LinkedList *list2)
{
    if (!list1 || !list1->head)
    {
        return list2;
    }
    if (!list2 || !list2->head)
    {
        return list1;
    }

    list1->tail->next = list2->head;
    list1->tail = list2->tail;
    list1->size += list2->size;

    free(list2);
    return list1;
}
