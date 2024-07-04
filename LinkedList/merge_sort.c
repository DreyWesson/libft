#include "LinkedList.h"

Node *setData(LinkedList *list, Node *target) {
    appendNode(list, target->data);
    return target->next;
}

LinkedList *merge(LinkedList *l1, LinkedList *l2) {
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
        nl2 = setData(merged, nl2->data);
    
    return merged;
}

LinkedList *mergeSort(LinkedList *list) {
    size_t mid = list->size / 2;
    size_t counter = 0;

    Node *tmp = list->head;
    // LinkedList *left;
    // LinkedList *right =
    // untangle the list

    while (counter < mid && tmp)
    {
        tmp = tmp->next;
        counter++;
    }
    
    printf("*%d\n", *(int *)tmp->data);
    (void)list;

    return list;
}









































// // Split the list into two halves
// Node *split(Node *head) {
//     Node *slow = head;
//     Node *fast = head->next;

//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     Node *middle = slow->next;
//     slow->next = NULL;
//     return middle;
// }

// // Merge two sorted lists
// Node *merge(Node *left, Node *right, int (*cmp)(const void *, const void *)) {
//     if (!left)
//         return right;
//     if (!right)
//         return left;

//     Node *result = NULL;

//     if (cmp(left->data, right->data) <= 0) {
//         result = left;
//         result->next = merge(left->next, right, cmp);
//     } else {
//         result = right;
//         result->next = merge(left, right->next, cmp);
//     }

//     return result;
// }

// // Merge sort for linked list
// Node *merge_sort(Node *head, int (*cmp)(const void *, const void *)) {
//     if (!head || !head->next)
//         return head;

//     Node *middle = split(head);
//     Node *left = merge_sort(head, cmp);
//     Node *right = merge_sort(middle, cmp);

//     return merge(left, right, cmp);
// }

// // Function to compare two integers
// int compare_int(const void *a, const void *b) {
//     return (*(int *)a - *(int *)b);
// }

// LinkedList *sort_list(LinkedList *list, int (*cmp)(const void *, const void *)) {
//     if (!list || !list->head)
//         return list;

//     list->head = merge_sort(list->head, cmp);

//     // Update tail
//     Node *tmp = list->head;
//     while (tmp->next) {
//         tmp = tmp->next;
//     }
//     list->tail = tmp;

//     return list;
// }