#include "LinkedList.h"

int main(void) {
    // int x = 42;
    // Node *test = create_node(&x);

    int arr[] = {34, 87, 94, 21, 42, 63, 84,105,};
    int arr2[] = {2, 4, 6, 8,10};
    LinkedList *list = create_list();
    LinkedList *list2 = create_list();
    size_t i = 0;
    while (i < (sizeof(arr)/ sizeof(int))) {
        appendNode(list, (void *)(arr + i));
        i++;
    }
    i = 0;
    while (i < (sizeof(arr2)/ sizeof(int))) {
        appendNode(list2, (void *)(arr2 + i));
        i++;
    }

    LinkedList *merged = merge(list, list2);
    mergeSort(merged);


    // int y = 35;
    // prependNode(list,(void *) &y);
    // printf("%zu %d\n", list->size, *(int *)list->tail->data);
    // reverse(list);
    // insert(list, &y, 1);
    // printList(list);
    // printf("\n\n");
    // delete(list, 5);
    // printf("-> %zu\n", list->size);
    // LinkedList *merged = merge_list(list, list2);


    // printList(list);
    // clearList(list);
    // clearList(list2);
    // bubblesort_list(merged);
    // LinkedList *halved = splitList(list);
    // printList(halved);
    // printList(merged);
    // printf("\n\n\n");
    // sort_list(merged, compare_int);
    printf("\n\n");
    printList(merged);
    printf("\n\n");
    // clearList(merged);
    // (void)merged;
    clearList(list);
    clearList(list2);
    clearList(merged);
    free(list);
    free(list2);
    free(merged);
    return (0);
}
