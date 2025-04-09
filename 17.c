#include <stdio.h>

#define SIZE 5  

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    printf("Rajan \t BCA 2A\nEnrolment No. \t 04717702024\n****************************\n");

    int arr[SIZE];
    printf("Enter %d elements: ", SIZE);
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, SIZE - 1);

    printf("Sorted Array using Merge Sort:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    return 0;
}
