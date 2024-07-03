#include "LinkedList.h"

int main(void) {
    // int x = 42;
    // Node *test = create_node(&x);

    int arr[] = {21, 42, 63, 84,105};
    LinkedList *list = create_list();
    int i = 0;
    while (i < 5) {
        // printf("%d\n", arr[i]);
        appendNode(list, (void *)(arr + i));
        i++;
    }
    if (list)
        printf("List is not empty\n");
    // prependNode(list, (void *)1);
    printList(list);
    (void) list;
    // printf("%d\n", *(int *)list->head->data);
    return (0);
}
