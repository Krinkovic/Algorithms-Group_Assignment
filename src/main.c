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
    char *input1[] = {"Ordered", "Reversed"};
    char *input2[] = {"Random", "Almost ordered"};
    int size[] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
    int average;

    for (int i = 0; i < 2; i ++) {
        fprintf(fp, "------------------------------\n");
        fprintf(fp, "%-10s %s\n\n","Input:", input1[i]);
        fprintf(fp, "%-10s %-10s\n", "Size n", "Operations op");
        for (int j = 0; j < 8; j++) {
            op = 0;
            unsigned int *arr = arrayGen(size[j]);
            func(arr, size[j], &op);
            fprintf(fp, "%-10d %-10d\n", size[j], op);
            fflush(fp);
        }
        fprintf(fp, "------------------------------\n\n");
    }
    for (int i = 0; i < 2; i ++) {
        fprintf(fp, "------------------------------\n");
        fprintf(fp, "%-10s %s\n\n","Input:", input2[i]);
        fprintf(fp, "%-10s %-10s\n", "Size n", "Operations op");
        for (int j = 0; j < 8; j++) {
            average = 0;
            for (int k = 0; k < 30; k++) {
                op = 0;
                unsigned int *arr = arrayGen(size[j]);
                func(arr, size[j], &op);
                average = average + (op - average) / (k + 1);
                fflush(fp);
            }
            fprintf(fp, "%-10d %-10d\n", size[j], average);
        }
        fprintf(fp, "------------------------------\n\n");
    }
}

void printArray(unsigned int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i < n - 1) ? ", " : "\n\n");
    }
}
