#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void **data;
    size_t size;
    size_t capacity;
} myArray;

myArray *create_array(size_t initial_capacity) {
    myArray *arr = (myArray *)malloc(sizeof(myArray));
    if (!arr) return NULL;

    arr->data = (void **)malloc(initial_capacity * sizeof(void *));
    if (!arr->data) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

int resize_array(myArray *arr, size_t new_capacity) {
    void **new_data = (void **)realloc(arr->data, new_capacity * sizeof(void *));
    if (!new_data) return -1;

    arr->data = new_data;
    arr->capacity = new_capacity;
    return 0;
}

int append(myArray *arr, void *element) {
    if (arr->size == arr->capacity) {
        if (resize_array(arr, arr->capacity * 2) != 0) {
            return -1;
        }
    }

    arr->data[arr->size++] = element;
    return 0;
}

int insert(myArray *arr, void *element, size_t pos) {
    if (pos > arr->size) return -1;
    if (arr->size == arr->capacity) {
        if (resize_array(arr, arr->capacity * 2) != 0) {
            return -1;
        }
    }

    memmove(&arr->data[pos + 1], &arr->data[pos], (arr->size - pos) * sizeof(void *));
    arr->data[pos] = element;
    arr->size++;
    return 0;
}

int delete(myArray *arr, size_t pos) {
    if (pos >= arr->size) return -1;

    memmove(&arr->data[pos], &arr->data[pos + 1], (arr->size - pos - 1) * sizeof(void *));
    arr->size--;
    return 0;
}

void clear_array(myArray *arr) {
    arr->size = 0;
}

void free_array(myArray *arr) {
    free(arr->data);
    free(arr);
}

void print_array(myArray *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", *(int *)arr->data[i]);
    }
    printf("\n");
}

int main() {
    myArray *arr = create_array(4);

    for (int i = 0; i < 10; i++) {
        int *num = (int *)malloc(sizeof(int));
        *num = i;
        append(arr, num);
    }

    print_array(arr);

    int *num = (int *)malloc(sizeof(int));
    *num = 100;
    insert(arr, num, 5);

    print_array(arr);

    delete(arr, 5);
    print_array(arr);

    clear_array(arr);
    print_array(arr);

    free_array(arr);
    return 0;
}
