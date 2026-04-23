// Kristoffer & Abdulsalam

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <time.h>
#include "../include/input_gen.h"
#include "../include/sorting.h"

void run(FILE *fp, void (*func)(unsigned int*, int, int*));
void printArray(unsigned int arr[], int n);

int main(void)
{
    srand(time(NULL)); // Seed random generation

    FILE *fp = fopen("output.txt", "w");
    fprintf(fp, "======================\n");
    fprintf(fp, "Algorithm: Bubble sort\n");
    fprintf(fp, "======================\n");
    run(fp, bubbleSort);

    fprintf(fp, "=========================\n");
    fprintf(fp, "Algorithm: Insertion sort\n");
    fprintf(fp, "=========================\n");
    run(fp, insertionSort);

    fprintf(fp, "====================\n");
    fprintf(fp, "Algorithm: Quicksort\n");
    fprintf(fp, "====================\n");
    run(fp, quickSort);
    fclose(fp);
}

void run(FILE *fp, void (*func)(unsigned int*, int, int*))
{
    int op;
    int size[] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
    int average;

    fprintf(fp, "------------------------------\n");
    fprintf(fp, "%-10s %s\n\n","Input:", "Ordered");
    fprintf(fp, "%-10s %-10s\n", "Size n", "Operations op");
    for (int i = 0; i < 8; i++) {
        op = 0;
        unsigned int *arr = arrayGen(size[i]);
        func(arr, size[i], &op);
        fprintf(fp, "%-10d %-10d\n", size[i], op);
        fflush(fp);
        free(arr);
    }

    fprintf(fp, "------------------------------\n");
    fprintf(fp, "%-10s %s\n\n","Input:", "Reversed");
    fprintf(fp, "%-10s %-10s\n", "Size n", "Operations op");
    for (int i = 0; i < 8; i++) {
        op = 0;
        unsigned int *arr = arrayGen(size[i]);
        reverse(arr, size[i]);
        func(arr, size[i], &op);
        fprintf(fp, "%-10d %-10d\n", size[i], op);
        fflush(fp);
        free(arr);
    }
    fprintf(fp, "------------------------------\n");
    fprintf(fp, "%-10s %s\n\n","Input:", "Random");
    fprintf(fp, "%-10s %-10s\n", "Size n", "Operations op");
    for (int i = 0; i < 8; i++) {
        average = 0;
        for (int j = 0; j < 30; j++) {
            op = 0;
            unsigned int *arr = arrayGen(size[i]);
            randomized(arr, size[i]);
            func(arr, size[i], &op);
            average = average + (op - average) / (j + 1);
            fflush(fp);
            free(arr);
        }
        fprintf(fp, "%-10d %-10d\n", size[i], average);
    }

    fprintf(fp, "------------------------------\n");
    fprintf(fp, "%-10s %s\n\n","Input:", "Almost Ordered");
    fprintf(fp, "%-10s %-10s\n", "Size n", "Operations op");
    for (int i = 0; i < 8; i++) {
        average = 0;
        for (int j = 0; j < 30; j++) {
            op = 0;
            unsigned int *arr = arrayGen(size[i]);
            almost_ordered(arr, size[i]);
            func(arr, size[i], &op);
            average = average + (op - average) / (j + 1);
            fflush(fp);
            free(arr);
        }
        fprintf(fp, "%-10d %-10d\n", size[i], average);
    }
    fprintf(fp, "------------------------------\n\n");
}

void printArray(unsigned int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i < n - 1) ? ", " : "\n\n");
    }
}
