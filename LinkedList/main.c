#include "LinkedList.h"

int main(void) {
    int arr[] = {34, 87, 94, 21, 42, 63, 105, 84};
    int arr2[] = {8, 7, 6, 2, 10};
    LinkedList *list = create_list();
    LinkedList *list2 = create_list();
    size_t i = 0;
    while (i < (sizeof(arr)/ sizeof(int))) {
        appendNode(list, (void *)&arr[i]);
        i++;
    }
    i = 0;
    while (i < (sizeof(arr2)/ sizeof(int))) {
        appendNode(list2, (void *)&arr2[i]);
        i++;
    }

    LinkedList *merged = merge(list, list2);
    LinkedList *sorted = mergeSort(merged);
    printList(sorted);
    if (list && list->head)
        clearList(list);
    if (list2 && list2->head)
        clearList(list2);
    if (merged && merged->head)
        clearList(merged);
    if (sorted && sorted->head)
        clearList(sorted);

    free(list);
    free(list2);
    free(merged);
    free(sorted);
    return 0;
}
