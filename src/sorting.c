// Kristoffer & Abdulsalam

#include "../include/sorting.h"

void bubbleSort(unsigned int arr[], int n, int *op)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            (*op)++; // Counting the basic operation: the if statement
        }
    }
}

void insertionSort(unsigned int arr[], int n, int *op)
{
    for (int i = 1; i < n; i++) {
        unsigned int v = arr[i]; // The element to be inserted
        int j = i - 1; // The index of the last sorted element

        // Shift elements right until correct postion found
        while (j >= 0 && arr[j] > v) {
            (*op)++; // Counting the basic operation: the while loop runs
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0) {
            (*op)++; // Counting the basic operation: the while loop does not run
        }
        arr[j + 1] = v; // Insert the element at its correct position
    }
}

static int hoarePartition(unsigned int arr[], int l, int r, int *op)
{
    unsigned int p = arr[l]; // Choose the first element as pivot
    int i = l;
    int j = r + 1;

    do {
        do {
            i++;
            (*op)++; // Counting the basic operation: each comparison with pivot
        } while (i <= r && arr[i] < p);
        do {
            j--;
            (*op)++; // Counting the basic operation: each comparison with pivot
        } while (j > l && arr[j] > p);

        if (i >= j) break;

        unsigned int temp = arr[i];
        arr[i] = arr[j];
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
static void quickSortHelper(unsigned int arr[], int l, int r, int *op)
{
    if (l < r) {
        int s = hoarePartition(arr, l, r, op);
        quickSortHelper(arr, l, s - 1, op);
        quickSortHelper(arr, s + 1, r, op);

    }
}

void quickSort(unsigned int arr [], int n, int *op)
{
    quickSortHelper(arr, 0, n - 1, op);
}
