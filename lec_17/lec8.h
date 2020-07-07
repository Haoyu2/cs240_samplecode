#ifndef LEC8_H
#define LEC8_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>   	// for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> 	// for sleep()

long factorial(int n);

void testingRecursion();




void swap(int a[], int i, int j);
void printArray(int a[], int len);
void printSS(char *a[], int len);
void testingSort();



// Sort.c



int charToInt(char s[]);

void shellSort(int a[], int len);
void mergeSort(int a[], int len);




void selectionSortSpeed(int a[], int len);

void insertionSortSpeed(int a[], int len);
void shellSortSpeed(int a[], int len);
void mergeSortSpeed(int a[], int len);
void quickSortSpeed(int a[], int len);




// Random.c
void testingRand();
void randArrayRange(int a[], int len, int max);
void randArray(int a[], int len);







#endif