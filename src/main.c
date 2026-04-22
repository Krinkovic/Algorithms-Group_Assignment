// Kristoffer & Abdulsalam

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/input_gen.h"
#include "../include/sorting.h"

void printArray(unsigned int arr[], int n);

int main(void)
{
    srand(time(NULL)); // Seed random generation
    int n = 1000; // Size of arrays
    int count; // To count basic operations
    int size = sizeof(unsigned int) * n; // Size of the arrays

    unsigned int *ord = arrayGen(n);
    if (ord == NULL) {
        printf("Not enough memory");
        exit(1);
    }

    unsigned int *rev = reverse(ord, n);
    if (rev == NULL) {
        printf("Not enough memory\n");
        exit(1);
    }

    unsigned int *rand = malloc(size);
    randomized(memcpy(rand, ord, size), n);
    if (rand == NULL) {
        printf("Not enough memory\n");
        exit(1);
    }

    unsigned int *almOrd = malloc(size);
    almost_ordered(memcpy(almOrd, ord, size), n);
    if (almOrd == NULL) {
        printf("Not enough memory\n");
        exit(1);
    }

    printf("SORTING ALGORITHM TESTING\n");
    // Commented out printing of arrays when running large arrays
    // printf("Starting arrays:\n\n");
    // printf("Ordered:\n");
    // printArray(ord, n);
    // printf("Reverse:\n");
    // printArray(rev, n);
    // printf("Random:\n");
    // printArray(rand, n);
    // printf("Almost ordered:\n");
    // printArray(almOrd, n);

    printf("\n---BUBBLE SORT---\n");
    // Create copies of arrays for bubble sort
    unsigned int *bubbleOrd = malloc(size);
    memcpy(bubbleOrd, ord, size);
    unsigned int *bubbleRev = malloc(size);
    memcpy(bubbleRev, rev, size);
    unsigned int *bubbleRand = malloc(size);
    memcpy(bubbleRand, rand, size);
    unsigned int *bubbleAlmOrd = malloc(size);
    memcpy(bubbleAlmOrd, almOrd, size);

    count = 0;
    bubbleSort(bubbleOrd, n, &count);
    printf("Ordered sorted in %d operations:\n", count);
    // printArray(bubbleOrd, n);
    count = 0;
    bubbleSort(bubbleRev, n, &count);
    printf("Reversed sorted in %d operations:\n", count);
    // printArray(bubbleRev, n);
    count = 0;
    bubbleSort(bubbleRand, n, &count);
    printf("Randomized sorted in %d operations:\n", count);
    // printArray(bubbleRand, n);
    count = 0;
    bubbleSort(bubbleAlmOrd, n, &count);
    printf("Almost ordered sorted in %d operations:\n", count);
    // printArray(bubbleAlmOrd, n);

    printf("\n---INSERTION SORT---\n");
    // Create copies of arrays for insertion sort
    unsigned int *insertionOrd = malloc(size);
    memcpy(insertionOrd, ord, size);
    unsigned int *insertionRev = malloc(size);
    memcpy(insertionRev, rev, size);
    unsigned int *insertionRand = malloc(size);
    memcpy(insertionRand, rand, size);
    unsigned int *insertionAlmOrd = malloc(size);
    memcpy(insertionAlmOrd, almOrd, size);

    count = 0;
    insertionSort(bubbleOrd, n, &count);
    printf("Ordered sorted in %d operations:\n", count);
    // printArray(insertionOrd, n);
    count = 0;
    insertionSort(insertionRev, n, &count);
    printf("Reversed sorted in %d operations:\n", count);
    // printArray(insertionRev, n);
    count = 0;
    insertionSort(insertionRand, n, &count);
    printf("Randomized sorted in %d operations:\n", count);
    // printArray(insertionRand, n);
    count = 0;
    insertionSort(insertionAlmOrd, n, &count);
    printf("Almost ordered sorted in %d operations:\n", count);
    // printArray(insertionAlmOrd, n);

    printf("\n---QUICKSORT---\n");
    // Create copies of arrays for quicksort
    unsigned int *quickOrd = malloc(size);
    memcpy(quickOrd, ord, size);
    unsigned int *quickRev = malloc(size);
    memcpy(quickRev, rev, size);
    unsigned int *quickRand = malloc(size);
    memcpy(quickRand, rand, size);
    unsigned int *quickAlmOrd = malloc(size);
    memcpy(quickAlmOrd, almOrd, size);


    count = 0;
    quickSort(quickOrd, n, &count);
    printf("Ordered sorted in %d operations:\n", count);
    // printArray(quickOrd, n);
    count = 0;
    quickSort(quickRev, n, &count);
    printf("Reversed sorted in %d operations:\n", count);
    // printArray(quickRev, n);
    count = 0;
    quickSort(quickRand, n, &count);
    printf("Randomized sorted in %d operations:\n", count);
    // printArray(quickRand, n);
    count = 0;
    quickSort(quickAlmOrd, n, &count);
    printf("Almost ordered sorted in %d operations:\n", count);
    // printArray(quickAlmOrd, n);
}

void printArray(unsigned int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i < n - 1) ? ", " : "\n\n");
    }
}
