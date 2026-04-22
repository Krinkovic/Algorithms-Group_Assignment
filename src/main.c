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
    int n = 10; // Size of arrays
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

    // Test sorting
    //Create copies of all the arrays so all algorithms sort the same arrays
    unsigned int *bubbleOrd = malloc(size);
    bubbleOrd = memcpy(bubbleOrd, ord, size);

    unsigned int *bubbleRev = malloc(size);
    bubbleRev = memcpy(bubbleRev, rev, size);

    unsigned int *bubbleRand = malloc(size);
    bubbleRand = memcpy(bubbleRand, rand, size);

    unsigned int *bubbleAlmOrd = malloc(size);
    bubbleAlmOrd = memcpy(bubbleAlmOrd, almOrd, size);

    unsigned int *insertionOrd = malloc(size);
    insertionOrd = memcpy(insertionOrd, ord, size);

    unsigned int *insertionRev = malloc(size);
    insertionRev = memcpy(insertionRev, rev, size);

    unsigned int *insertionRand = malloc(size);
    insertionRand = memcpy(insertionRand, rand, size);

    unsigned int *insertionAlmOrd = malloc(size);
    insertionAlmOrd = memcpy(insertionAlmOrd, almOrd, size);

    unsigned int *quickOrd = malloc(size);
    quickOrd = memcpy(quickOrd, ord, size);

    unsigned int *quickRev = malloc(size);
    quickRev = memcpy(quickRev, rev, size);

    unsigned int *quickRand = malloc(size);
    quickRand = memcpy(quickRand, rand, size);

    unsigned int *quickAlmOrd = malloc(size);
    quickAlmOrd = memcpy(quickAlmOrd, almOrd, size);

    printf("SORTING ALGORITHM TESTING\n");
    printf("Starting arrays:\n\n");
    printf("Ordered:\n");
    printArray(ord, n);
    printf("Reverse:\n");
    printArray(rev, n);
    printf("Random:\n");
    printArray(rand, n);
    printf("Almost ordered:\n");
    printArray(almOrd, n);

    printf("\n---BUBBLE SORT---\n");
    count = 0;
    bubbleSort(bubbleOrd, n, &count);
    printf("Ordered sorted in %d operations:\n", count);
    printArray(bubbleOrd, n);
    count = 0;
    bubbleSort(bubbleRev, n, &count);
    printf("Reversed sorted in %d operations:\n", count);
    printArray(bubbleRev, n);
    count = 0;
    bubbleSort(bubbleRand, n, &count);
    printf("Randomized sorted in %d operations:\n", count);
    printArray(bubbleRand, n);
    count = 0;
    bubbleSort(bubbleAlmOrd, n, &count);
    printf("Almost ordered sorted in %d operations:\n", count);
    printArray(bubbleAlmOrd, n);
}

void printArray(unsigned int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i < n - 1) ? ", " : "\n\n");
    }
}
