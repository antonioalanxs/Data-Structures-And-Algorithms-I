//
// Created by antonioalanxs.
//

#include <iostream>
#include "Array.h"

using std::cout;
using std::endl;

void Create(TArray &a) {
    a.size = 0;
    for (int & value : a.values) {
        value = 0;
    }
}

void PushFront(TArray &a, int value) {
    if (!(a.size > LENGHT)) {
        int index = a.size;
        for (index; index >= 0; index--) { // We shift everything to the right to free up the first
                                           // position.
            a.values[index + 1] = a.values[index];
        }
        a.values[0] = value; // We introduce the value in the first position.
        a.size++;
    }
}

void PushBack(TArray &a, int value) {
    if (!(a.size > LENGHT)) {
        a.values[a.size] = value;
        a.size++;
    }
}

void Remove(TArray &a, int value) {
    if (a.size != 0) {
        bool flag = false;
        int size = a.size - 1;
        int index = 0; // It will store the position where the value to be deleted is found.
        while (!flag && index <= size) {
            flag = a.values[index] == value;
            if (!flag) {
                index++;
            }
        }
        if (flag) {
            if (index != size) { // The value is at the first position or at an intermediate position. We move everything to the
                                 // left.
                for (int i = index; i <= size; i++) {
                    a.values[i] = a.values[i+1];
                }
            }
            a.size = a.size - 1;
        }
    }
}

void Merge(TArray &a, TArray another) {
    int another_size = another.size;
    for (int index = 0; index < another_size; index++) {
        PushBack(a, At(another, index));
    }
}

void QuickSort(TArray &a) {
    if (Size(a) >= 2) {
        int pivot = Front(a); // Random number for having a comparison judgment.
        TArray items_lower;
        Create(items_lower);
        TArray items_greater;
        Create(items_greater);

        int size = a.size;
        for (int index = 1; index < size; index++) { // We start ahead of the pivot so as not to compare him with
                                                     // himself.
            int item = At(a, index);
            if (item <= pivot) {
                PushBack(items_lower, item);
            } else {
                PushBack(items_greater, item);
            }
        }

        QuickSort(items_lower);
        PushBack(items_lower, pivot);
        QuickSort(items_greater);
        Merge(items_lower, items_greater);
        a = items_lower;
    }
}

void BubbleSort(TArray &a) {
    int size = Size(a);
    for (int i = 0; i < size; i++) {
        int size_of_swapping = size - i - 1; // "- i" for narrowing down the array and "- 1" for not swapping with
                                             // "Size(a) + 1" at the last iteration ("j + 1").
        for (int j = 0; j < size_of_swapping; j++) {
            int prev = At(a, j);
            int post = At(a, j + 1);
            if (prev > post) {
                int aux_prev = prev;
                a.values[j] = post;
                a.values[j + 1] = aux_prev;
            }
        }
    }
}

int At(TArray a, int index) {
    if (!(index > (a.size - 1)) && index >= 0) {
        return a.values[index];
    }
    return -1;
}

int Front(TArray a) {
    if (a.size != 0) {
        return a.values[0];
    }
    return -1;
}

int Back(TArray a) {
    if (a.size != 0) {
        return a.values[a.size - 1]; // Because every time we introduce a value we increase size by 1 and that is the
                                     // position that remains empty to introduce the next value and so on. This is
                                     // because on C++ arrays start at 0.
    }
    return -1;
}

bool Empty(TArray a) {
    return a.size == 0;
}

bool LinearSearch(TArray a, int target) {
    if (a.size > 0) {
        int size = a.size - 1;
        int index = 0;
        bool flag = false;
        while (!flag && index <= size) {
            flag = a.values[index] == target;
            if (!flag) {
                index++;
            }
        }
        return flag;
    }
    return false;
}

bool BinarySearch(TArray a, int target, int left, int right) {
    if (right >= left) {
        int middle = left + (right - left) / 2; // Formula to calculate the middle element.
        int current_value = a.values[middle];

        if (target == current_value) {
            return true;
        }

        if (target > current_value) {
            return BinarySearch(a, target, middle + 1, right);
        }

        return BinarySearch(a, target, left, middle - 1); // target < current_value
    }
    return false;
}

int Size(TArray a) {
    return a.size;
}

void Show(TArray a) {
    int size = a.size - 1;
    cout << "[";
    for (int index = 0; index <= size; index++) {
        cout << a.values[index];
        if (index < size) {
            cout << ", ";
        }
    }
    cout << "]";
}
