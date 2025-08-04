#include <stdio.h>
#include <time.h>
#define MAX 500

void quickSort(int[], int, int);
int partition(int[], int, int);


int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high, temp;

    while (1) {
        while (pivot > a[i] && i <= high  ) i++;
        while (pivot > a[j]) j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quickSort(int a[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main() {
    int a[MAX], i, n;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nArray before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();

    printf("\nArray after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
