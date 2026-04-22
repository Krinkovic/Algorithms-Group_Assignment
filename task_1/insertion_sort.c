// 2026 Abdulsalam & Kristoffer

void insertionSort(unsigned int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        unsigned int v = arr[i]; // The element to be inserted
        int j = i - 1; // The index of the last sorted element

        // Shift elements right until correct postion found
        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v; // Insert the element at its correct position
    }
}

// #include <stdio.h>
// int main(void) // For testing
// {
//     unsigned int arr[] = {6, 3, 9, 10, 1, 3};
//     int n = 6;
//     insertionSort(arr, n);
//     printf("sorted numbers:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%u\n", arr[i]);

//     }
//     return 0;
// }
