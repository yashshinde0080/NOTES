#include <stdio.h>
#include <time.h>


// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i = 0, j = 0, k = p;

    // Merge the temp arrays back into arr[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of M[], if any
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}



// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    clock_t s, e;

    s = clock();
    mergeSort(arr, 0, size - 1);
    e = clock();

    printf("Sorted array:\n");
    printArray(arr, size);
    printf("\nTime taken: %f seconds\n", (double)(e - s) / CLOCKS_PER_SEC);

    return 0;
}
