//
// Created by antonioalanxs.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#define LENGHT 100 // The one you want.

typedef struct TArray {
    int size;
    int values [LENGHT]; // It initializes automatically.
} TArray;

// Generation constructors:
void Create(TArray &a);

// Modification constructors:
void PushFront(TArray &a, int value);
void PushBack(TArray &a, int value);
void Remove(TArray &a, int value);
void Merge(TArray &a, TArray another);
void QuickSort(TArray &a);
void BubbleSort(TArray &a);

// Selective observers:
int At(TArray a, int index);
int Front(TArray a);
int Back(TArray a);

// Non-selective observers:
bool Empty(TArray a);
bool LinearSearch(TArray a, int target);
bool BinarySearch(TArray a, int target, int left, int right);
int Size(TArray a);
void Show(TArray a);

#endif
