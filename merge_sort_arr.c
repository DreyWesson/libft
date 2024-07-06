#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct myArray
{
    int *arr;
    size_t size;
} myArray;

myArray arrConstructor(int *arr, size_t size)
{
    myArray data;
    data.arr = arr;
    data.size = size;
    return data;
}

myArray *merge(myArray *arr1, myArray *arr2)
{

    myArray *newArr = (myArray *)calloc(1, sizeof(myArray));
    if (!newArr)
        return (printf("Failed to alloc mem\n"), NULL);
    size_t left = 0, right = 0, primary = 0;

    newArr->arr = (int *)calloc(sizeof(int), (arr1->size + arr2->size));
    if (!newArr->arr)
        return (printf("Failed to alloc mem\n"), NULL);

    while (left < arr1->size && right < arr2->size)
    {
        size_t isLeftLesser = (arr1->arr[left] < arr2->arr[right]);

        newArr->arr[primary++] = isLeftLesser ? arr1->arr[left++] : arr2->arr[right++];
    }
    while (left < arr1->size)
        newArr->arr[primary++] = arr1->arr[left++];
    while (right < arr2->size)
        newArr->arr[primary++] = arr2->arr[right++];
    newArr->size = primary;

    return newArr;
}

int memoryAllocations(myArray **leftContainer, myArray **rightContainer, size_t mid, size_t total_size)
{
    char *failedMsg = "Mem alloc failed!\n";
    *leftContainer = (myArray *)calloc(1, sizeof(myArray));
    if (!*leftContainer)
        return (printf("%s", failedMsg), 0);

    *rightContainer = (myArray *)calloc(1, sizeof(myArray));
    if (!*rightContainer)
        return (printf("%s", failedMsg), 0);


    (*leftContainer)->arr = (int *)calloc(sizeof(int), mid);
    if (!(*leftContainer)->arr)
        return (printf("%s", failedMsg), 0);

    (*rightContainer)->arr = (int *)calloc(sizeof(int), total_size - mid);
    if (!(*rightContainer)->arr)
        return (printf("%s", failedMsg), 0);

    return (1);
}

myArray *divideArr(myArray *arr)
{
    if (arr->size <= 1)
        return arr;

    size_t mid = arr->size / 2;
    myArray *leftContainer = NULL;
    myArray *rightContainer = NULL;

    if (!memoryAllocations(&leftContainer, &rightContainer, mid, arr->size))
        return NULL;

    leftContainer->size = mid;
    rightContainer->size = arr->size - mid;

    for (size_t i = 0; i < mid; i++)
        leftContainer->arr[i] = arr->arr[i];

    for (size_t i = mid; i < arr->size; i++)
        rightContainer->arr[i - mid] = arr->arr[i];

    myArray *left = divideArr(leftContainer);
    myArray *right = divideArr(rightContainer);
    myArray *merged = merge(left, right);
    if (left != leftContainer)
    {
        free(left->arr);
        free(left);
    }
    if (right != rightContainer)
    {
        free(right->arr);
        free(right);
    }
    free(leftContainer->arr);
    free(rightContainer->arr);
    free(leftContainer);
    free(rightContainer);
    return merged;
}

int main(int argc, char **argv)
{
    size_t size1 = 5;
    int arr1[] = {7, 8, 1, 4, 3};
    size_t size2 = 10;
    int arr2[] = {3, 6, 5, 42, 35, 64, 72, 105, 2, 9};
    myArray array1 = arrConstructor(arr1, size1);
    myArray array2 = arrConstructor(arr2, size2);
    myArray *merged = merge(&array1, &array2);
    if (!merged)
        return (printf("Unexpected value!\n"), 1);
    myArray *sorted = divideArr(merged);
    if (!sorted)
        return (1);
    size_t i = 0;
    while (i < sorted->size)
    {
        printf("%d, ", sorted->arr[i]);

        i++;
    }
    printf("\n");
    free(sorted->arr);
    free(sorted);
    free(merged->arr);
    free(merged);

    (void)merged;
    (void)array1;
    (void)array2;
    (void)argv;
    (void)argc;
    return (0);
}