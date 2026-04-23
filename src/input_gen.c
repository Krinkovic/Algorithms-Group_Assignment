// Kristoffer & Abdulsalam

#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../include/input_gen.h"

#define VARIANCE 10

unsigned int* arrayGen(int n)
{
    int prev = 0;
    unsigned int * arr = malloc(sizeof(unsigned int) * n);
    if (arr == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = prev + 1 + rand() % VARIANCE; // Randomized so each number will be a random number bigger than the previous, based on variance
        prev = arr[i];
    }
    return arr;
}

void reverse(unsigned int arr[], int n)
{
    unsigned int * rev = malloc(sizeof(unsigned int) * n);
    for (int i = 0; i < n; i++) {
        rev[i] = arr[n - 1 - i];
    }
    memcpy(arr, rev, n);
    free(rev);
}

void randomized(unsigned int arr[], int n)
{
    for (size_t i = n - 1; i > 0; i--) {

        size_t j = rand() % (i + 1); // Generate random index between 0 and i
        unsigned int temp = arr[i]; // Swap array[i] and array[j]
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void almost_ordered(unsigned int arr[], int n)
{
    int swaps = n / 100 * 4 / 2;
    if (swaps == 0) swaps = 1;

    for (int i = 0; i < swaps; i++) { // swap ≈4% of items. TODO: Guard against unlikely, but possible scenario where the same items get swapped twice, resulting in no change.
        int i1 = rand() % n;
        int i2;
        do {
            i2 = rand() % n;
        } while (i2 == i1);
        int temp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = temp;
    }
}
