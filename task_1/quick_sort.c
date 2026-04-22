// 2026 Abdulsalam & Kristoffer

#include <stdio.h>

void QuickSort(unsigned int arr[], int n);
static int HoarePartition(unsigned int arr[], int l, int r);

int main(void) // For testing
{
    unsigned int arr[] = {6, 3, 9, 10, 1, 5};
    int n = 6;
    QuickSort(arr, n);
    printf("sorted numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%u\n", arr[i]);
    }
    return 0;
}

static int HoarePartition(unsigned int arr[], int l, int r)
{
    unsigned int p = arr[l]; // Choose the first element as pivot
    int i = l;
    int j = r + 1;

    do {
        do { i++; } while (arr[i] < p);
        do { j--; } while (arr[j] > p);

        unsigned int temp = arr[i];
        arr [i] = arr[j];
        arr[j] = temp;

    } while (i < j);

    // Undo the last swap
    unsigned int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    // Move pivot to its correct position
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

// Sorts arr of n elements
static void QuickSortHelper(unsigned int arr[], int l, int r)
{
    if (l < r) {
        int s = HoarePartition(arr, l, r);
        QuickSortHelper(arr, l, s - 1);
        QuickSortHelper(arr, s + 1, r);

    }
}


void QuickSort(unsigned int arr [], int n)
{
    QuickSortHelper(arr, 0, n - 1);
}
