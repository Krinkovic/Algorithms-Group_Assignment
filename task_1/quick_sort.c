// 2026 Abdulsalam & Kristoffer

static int hoarePartition(unsigned int arr[], int l, int r)
{
    unsigned int p = arr[l]; // Choose the first element as pivot
    int i = l;
    int j = r + 1;

    do {
        do { i++; } while (arr[i] < p);
        do { j--; } while (arr[j] > p);

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
static void quickSortHelper(unsigned int arr[], int l, int r)
{
    if (l < r) {
        int s = hoarePartition(arr, l, r);
        quickSortHelper(arr, l, s - 1);
        quickSortHelper(arr, s + 1, r);

    }
}


void quickSort(unsigned int arr [], int n)
{
    quickSortHelper(arr, 0, n - 1);
}

// #include <stdio.h>
// int main(void) // For testing
// {
//     unsigned int arr[] = {6, 3, 9, 10, 1, 5};
//     int n = 6;
//     QuickSort(arr, n);
//     printf("sorted numbers:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%u\n", arr[i]);
//     }
//     return 0;
// }
