#include <iostream>
#include "Array.h"

using std::cout;
using std::endl;

int main() {
    TArray a;
    Create(a);

    cout << Size(a) << endl; // 0

    cout << Empty(a) << endl; // 1

    PushFront(a, 1);
    PushFront(a, 2);
    Show(a); // [2, 1]
    cout << endl;
    cout << Size(a) << endl; // 2
    PushFront(a, 3);
    PushFront(a, 4);
    cout << Empty(a) << endl; // 0
    Show(a); // [4, 3, 2, 1]
    cout << endl;

    PushBack(a, 0);
    PushBack(a, 0);
    Show(a); // [4, 3, 2, 1, 0, 0]
    cout << endl;

    Remove(a, 4);
    Show(a); // [3, 2, 1, 0, 0]
    cout << endl;

    cout << At(a, -1000) << endl; // -1
    cout << At(a, 9999) << endl; // -1
    cout << At(a, 2) << endl; // 1

    cout << Front(a) << endl; // 3
    cout << Back(a) << endl; // 0

    cout << Size(a) << endl; // 5

    cout << LinearSearch(a, 3) << endl; // 1
    cout << LinearSearch(a, 0) << endl; // 1
    cout << LinearSearch(a, 1) << endl; // 1
    cout << LinearSearch(a, -22) << endl; // 0

    TArray to_merge;
    Create(to_merge);
    for (int index = 0; index <= 5; index++) {
        PushBack(to_merge, index);
    }
    TArray to_merge_2;
    Create(to_merge_2);
    for (int index = 5; index <= 10; index++) {
        PushBack(to_merge_2, index);
    }
    Merge(to_merge, to_merge_2);
    Show(to_merge); // [0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10]
    cout << endl;

    TArray to_sort;
    Create(to_sort);
    PushBack(to_sort, 5);
    PushBack(to_sort, 4);
    PushBack(to_sort, 3);
    PushBack(to_sort, 2);
    PushBack(to_sort, 1);
    PushBack(to_sort, 0);
    QuickSort(to_sort);
    Show(to_sort); // [0, 1, 2, 3, 4, 5]
    cout << endl;

    TArray to_sort_2;
    Create(to_sort_2);
    PushBack(to_sort_2, -1);
    PushBack(to_sort_2, -1);
    PushBack(to_sort_2, 0);
    PushBack(to_sort_2, -1);
    QuickSort(to_sort_2);
    Show(to_sort_2); // [-1, -1, -1, 0]
    cout << endl;

    cout << BinarySearch(to_sort, 0, Front(to_sort), Back(to_sort)) << endl; // 1
    cout << BinarySearch(to_sort, 3, Front(to_sort), Back(to_sort)) << endl; // 1
    cout << BinarySearch(to_sort, 5, Front(to_sort), Back(to_sort)) << endl; // 1
    cout << BinarySearch(to_sort, -1, Front(to_sort), Back(to_sort)) << endl; // 0
    cout << BinarySearch(to_sort, 6, Front(to_sort), Back(to_sort)) << endl; // 0

    TArray to_sort_3;
    Create(to_sort_3);
    PushBack(to_sort_3, 5);
    PushBack(to_sort_3, 4);
    PushBack(to_sort_3, 3);
    PushBack(to_sort_3, 2);
    PushBack(to_sort_3, 1);
    PushBack(to_sort_3, 0);
    Show(to_sort_3);
    cout << endl;
    BubbleSort(to_sort_3);
    Show(to_sort_3); // [0, 1, 2, 3, 4, 5]
    cout << endl;

    return 0;
}
