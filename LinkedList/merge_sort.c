#include "LinkedList.h"

// Split the list into two halves
Node *split(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *middle = slow->next;
    slow->next = NULL;
    return middle;
}

// Merge two sorted lists
Node *merge(Node *left, Node *right, int (*cmp)(const void *, const void *)) {
    if (!left)
        return right;
    if (!right)
        return left;

    Node *result = NULL;

    if (cmp(left->data, right->data) <= 0) {
        result = left;
        result->next = merge(left->next, right, cmp);
    } else {
        result = right;
        result->next = merge(left, right->next, cmp);
    }

    return result;
}

// Merge sort for linked list
Node *merge_sort(Node *head, int (*cmp)(const void *, const void *)) {
    if (!head || !head->next)
        return head;

    Node *middle = split(head);
    Node *left = merge_sort(head, cmp);
    Node *right = merge_sort(middle, cmp);

    return merge(left, right, cmp);
}

// Function to compare two integers
int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

LinkedList *sort_list(LinkedList *list, int (*cmp)(const void *, const void *)) {
    if (!list || !list->head)
        return list;

    list->head = merge_sort(list->head, cmp);

    // Update tail
    Node *tmp = list->head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    list->tail = tmp;

    return list;
}