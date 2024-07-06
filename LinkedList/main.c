#include "LinkedList.h"

int main(void)
{
    // int arr[] = {34, 87, 94, 21, 42, 63, 105, 84};
    // int arr2[] = {8, 7, 6, 2, 10};
    // LinkedList *list = create_list();
    // LinkedList *list2 = create_list();
    // size_t i = 0;
    // while (i < (sizeof(arr)/ sizeof(int))) {
    //     appendNode(list, (void *)&arr[i]);
    //     i++;
    // }
    // i = 0;
    // while (i < (sizeof(arr2)/ sizeof(int))) {
    //     appendNode(list2, (void *)&arr2[i]);
    //     i++;
    // }
    // int y = 40;
    // appendNode(list2, &y);

    // LinkedList *merged = merge(list, list2);
    // LinkedList *sorted = mergeSort(merged);

    // printList(sorted);
    // destroyList(list);
    // destroyList(list2);
    // destroyList(merged);
    // destroyList(sorted);

    //
    // STACK
    //
    // int arr[] = {34, 87, 94, 21, 42, 63, 105, 84};
    // size_t capacity = sizeof(arr)/ sizeof(int);
    // Stack *st = createStack(capacity);
    // size_t i = 0;

    // while (i < capacity) {
    //     push_stack(st, (void *)&arr[i]);
    //     i++;
    // }
    // printList(st->list);
    // printf("==%d==\n", *(int *)(peek_stack(st)));
    // // i = 0;
    // // while (i < capacity - 2)
    // // {
    // //     pop_stack(st);
    // //     i++;
    // // }
    // destroy_stack(st);
    printf("%s\n", isMatchingParenthesis("{(097876})}[]") ? "balanced"
                                                         : "not balanced");

    return 0;
}
