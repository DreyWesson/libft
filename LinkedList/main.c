#include "LinkedList.h"

int main(void) {
    // int x = 42;
    // Node *test = create_node(&x);

    int arr[] = {21, 42, 63, 84,105};
    int arr2[] = {2, 4, 6, 8,10};
    LinkedList *list = create_list();
    LinkedList *list2 = create_list();
    int i = 0;
    while (i < 5) {
        appendNode(list, (void *)(arr + i));
        appendNode(list2, (void *)(arr2 + i));
        i++;
    }

    // int y = 35;
    // prependNode(list,(void *) &y);
    // printf("%zu %d\n", list->size, *(int *)list->tail->data);
    // reverse(list);
    // insert(list, &y, 1);
    // printList(list);
    // printf("\n\n");
    // delete(list, 5);
    // printf("-> %zu\n", list->size);
    LinkedList *merged = merge_list(list, list2);

    // printList(list);
    // clearList(list);
    // clearList(list2);
    // bubblesort_list(merged);
    // LinkedList *halved = splitList(list);
    // printList(halved);
    printList(merged);
    printf("\n\n\n");
    sort_list(merged, compare_int);
    printList(merged);
    clearList(merged);
    (void)merged;
    // free(list);
    // free(list2);
    free(merged);
    return (0);
}
