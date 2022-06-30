//
// Created by antonioalanxs.
//

#include <iostream>
#include "SinglyLinkedList.h"

using std::cout;
using std::endl;

int main() { // Quick test!
    TList l;
    Create(l); // l = nullptr

    PushFront(l, 1);
    Clear(l);
    cout << Empty(l) << endl; // 1

    PushFront(l, 2);
    PushFront(l, 3);
    PushFront(l, 4);
    PushFront(l, 5);
    cout << Size(l) << endl; // 4
    PushBack(l, 6);
    PushBack(l, 7);
    cout << Size(l) << endl; // 6

    cout << Empty(l) << endl; // 0

    cout << LinearSearch(l, 5) << endl; // 1
    cout << LinearSearch(l, 99) << endl; // 0
    cout << LinearSearch(l, 2) << endl; // 1
    cout << LinearSearch(l, 7) << endl; // 1

    Remove(l, 3);
    Show(l); // 5 -> 4 -> 2 -> 6 -> 7 -> NULL
    cout << endl;

    Remove(l, 5);
    Show(l); // 4 -> 2 -> 6 -> 7 -> NULL
    cout << endl;

    Remove(l, 7);
    Show(l); // 4 -> 2 -> 6 -> NULL
    cout << endl;

    PopBack(l);
    Show(l); // 4 -> 2 -> NULL
    cout << endl;

    cout << Front(l) << endl; // 4
    cout << Back(l); // 2

    return 0;
}
