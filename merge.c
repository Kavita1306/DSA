#include <stdio.h>

void merge(int arr1[], int arr2[], int size1, int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    while (i < size1)
        merged[k++] = arr1[i++];

    while (j < size2)
        merged[k++] = arr2[j++];
}

void merge_sort(int arr[], int size) {
    if (size < 2)
        return;

    int mid = size / 2;
    int left[mid], right[size - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    merge(left, right, mid, size - mid, arr);
}

int main() {
    int arr1[] = {1, 6, 2, 7};
    int arr2[] = {3, 9, 4, 8};
    int merged[8];

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    merge_sort(arr1, size1);
    merge_sort(arr2, size2);

    merge(arr1, arr2, size1, size2, merged);

    printf("Merged array is: ");
    for (int i = 0; i < size1 + size2; i++)
        printf("%d ", merged[i]);

    return 0;
}
