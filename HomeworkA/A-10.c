#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int* temp, int left, int mid, int right, int opt) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (opt == 0) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        } else {
            if (arr[i] >= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int* arr, int* temp, int left, int right, int opt) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid, opt);
        mergeSort(arr, temp, mid + 1, right, opt);
        merge(arr, temp, left, mid, right, opt);
    }
}

int main() {
    int n, opt;
    scanf("%d %d", &n, &opt);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    mergeSort(arr, temp, 0, n - 1, opt);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }

    free(arr);
    free(temp);

    return 0;
}