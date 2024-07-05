#include "LinkedList.h"

Node *setData(LinkedList *list, Node *target)
{
    appendNode(list, target->data);
    return target->next;
}

LinkedList *merge(LinkedList *l1, LinkedList *l2)
{
    Node *nl1 = l1->head;
    Node *nl2 = l2->head;
    LinkedList *merged = create_list();
    while (nl1 != NULL && nl2 != NULL)
    {
        int isLesser = *(int *)nl1->data < *(int *)nl2->data;
        if (isLesser)
            nl1 = setData(merged, nl1);
        else
            nl2 = setData(merged, nl2);
    }

    while (nl1 != NULL)
        nl1 = setData(merged, nl1);

    while (nl2 != NULL)
        nl2 = setData(merged, nl2);

    if (merged->head != NULL)
    {
        Node *tail = merged->head;
        while (tail->next != NULL)
            tail = tail->next;
        merged->tail = tail;
    }
    else
    {
        merged->tail = NULL;
    }

    return merged;
}

LinkedList *mergeSort(LinkedList *list) {
    if (list == NULL || list->size <= 1)
        return list;

    size_t mid = list->size / 2;
    size_t counter = 0;

    Node *tmp = list->head;

    LinkedList *left = create_list();
    LinkedList *right = create_list();
    while (counter < mid && tmp != NULL) {
        tmp = setData(left, tmp);
        counter++;
    }

    while (counter < list->size && tmp != NULL) {
        tmp = setData(right, tmp);
        counter++;
    }
    LinkedList *sortedLeft = mergeSort(left);
    LinkedList *sortedRight = mergeSort(right);
    LinkedList *sortedList = merge(sortedLeft, sortedRight);

    if (left != sortedLeft)
    {
        clearList(sortedLeft);
        free(sortedLeft);
    }
    if (right != sortedRight)
    {
        clearList(sortedRight);
        free(sortedRight);
    }

    clearList(left);
    clearList(right);

    free(left);
    free(right);

    return sortedList;
}
