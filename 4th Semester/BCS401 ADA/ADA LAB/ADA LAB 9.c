#include <stdio.h>
#include<time.h>
// function to swap the the position of two elements
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
void selectionSort(int array[], int size) {
for (int step = 0; step < size - 1; step++) {
int min_idx = step;
for (int i = step + 1; i < size; i++) {
// To sort in descending order, change > to < in this line.
// Select the minimum element in each loop.
if (array[i] < array[min_idx])
min_idx = i;
}
// put min at the correct position
swap(&array[min_idx], &array[step]);
}
}
// function to print an array
void printArray(int array[], int size) {
for (int i = 0; i < size; ++i) {
printf("%d ", array[i]);
}
printf("\n");
}
// driver code
int main() {
int data[] = {20, 12, 10, 15, 2};
clock_t s,e;
int size = sizeof(data) / sizeof(data[0]);
s=clock();
selectionSort(data, size);
e=clock();
printf("Sorted array in Acsending Order:\n");
printArray(data, size);
printf("\nTime taken:%f",(e-s)/CLOCKS_PER_SEC);
}
