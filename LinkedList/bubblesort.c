#include "./LinkedList.h"

LinkedList *bubblesort_list(LinkedList *list) {
    if (!list || !list->head)
        return list;
    Node *outer = list->head;

    while (outer != NULL)
    {
        Node *nested = outer;
        while (nested != NULL)
        {
            printf("%d", *(int *)nested->data);
            if (nested->next != NULL) 
                printf(",");
            if (*(int *)nested->data < *(int *)outer->data) {
                void *tmp = nested->data;
                nested->data = outer->data;
                outer->data = tmp;

            }
            nested = nested->next;
        }
        printf("\n");
        outer = outer->next;
    }
    

    return list;
}