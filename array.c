#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    void **data;
    size_t size;
    size_t capacity;
} myArray;

int resize_array(myArray *arr);
myArray *createArray(size_t capacity);
int appendArr(myArray *arr, void *element);
int insert(myArray *arr, void *element, size_t pos);
void printArr(myArray *arr);

myArray *createArray(size_t capacity)
{
    myArray *arr = (myArray *)malloc(sizeof(myArray));
    if (!arr)
        return NULL;

    arr->data = (void **)malloc(sizeof(void *) * capacity);
    if (!arr->data)
    {
        free(arr);
        return NULL;
    }

    arr->capacity = capacity;
    arr->size = 0;
    return arr;
}

int appendArr(myArray *arr, void *element)
{
    if (arr->size >= arr->capacity)
    {
        if (resize_array(arr) < 0)
            return -1;
    }
    arr->data[arr->size] = element;
    arr->size++;
    return 0;
}

int resize_array(myArray *arr)
{
    size_t newCapacity = arr->capacity * 2;
    void **new_data = (void **)realloc(arr->data, sizeof(void *) * newCapacity);

    if (!new_data)
        return -1;

    arr->data = new_data;
    arr->capacity = newCapacity;
    printf("Array resized to -> %ld\n", newCapacity);
    return 0;
}

int insert(myArray *arr, void *element, size_t pos)
{
    if (pos > arr->size) return -1;
    if (arr->size >= arr->capacity) {
        if (resize_array(arr) < 0)
            return -1;
    }
    memmove(&arr->data[pos + 1], &arr->data[pos],
            (arr->size - pos) * sizeof(void *));
    arr->data[pos] = element;
    arr->size++;
    return (0);
}

int removeAt(myArray *arr, size_t pos)
{
    if (pos > arr->size || arr->size >= arr->capacity)
        return -1;

    memmove(&arr->data[pos], &arr->data[pos + 1],
            (arr->size - pos) * sizeof(void *));

    arr->size--;
    return (0);
}

void *getIndex(myArray *arr, size_t pos) {
    if (pos >= arr->size)
     return NULL;
    return arr->data[pos];
}

void printArr(myArray *arr)
{
    size_t i = 0;

    printf("Arr Size [%ld]\n", arr->size);
    while (i < arr->size)
    {
        if (arr->data != NULL)
            printf("%ld\n", *(size_t *)arr->data[i]);
        i++;
    }
}

void garbageCollector(myArray *arr) {
    if (arr && arr->data)
        free(arr->data);
    if (arr)
        free(arr);
}

int main(void)
{
    size_t i = 0;
    size_t x = 8;
    size_t list[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,24};
    size_t size = sizeof(list) / sizeof(size_t);
    myArray *arr = createArray(size);

    while (i < size)
    {
        appendArr(arr, list + i);
        i++;
    }
    insert(arr, &x, 7);
    insert(arr, &x, 21);
    insert(arr, &x, 24);

    removeAt(arr, 0);
    printArr(arr);
    garbageCollector(arr);
    return (0);
}
