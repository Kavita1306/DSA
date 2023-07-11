#include <stdio.h>

void sort(int arr[], int n) {
    int i, j, size, temp;
    for (i = 0; i < n - 1; i++) {
        size = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[size]) {
                max = j;
            }
        }
        if (size!= i) {
            temp = arr[i];
            arr[i] = arr[size];
            arr[size] = temp;
        }
    }
}

int main() {
    int arr[] = { 10,4,27,34,89 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf(" Array Before sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    sort(arr, n);

    printf("\n Array After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
