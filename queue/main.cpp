#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

int main() { // Quick test!
    TQueue q;
    Create(q);

    Push(q, 1);
    Show(q); // 1 -> NULL
    cout << endl;
    Push(q, 2);
    Show(q); // 1 -> 2 -> NULL
    cout << endl;
    Push(q, 3);
    Show(q); // 1 -> 2 -> 3 -> NULL
    cout << endl;

    Pop(q);
    Pop(q);
    Show(q); // 3 -> NULL
    cout << endl;
    Pop(q); // Queue completely empty.
    Pop(q); // This should not give us an error.
    Show(q); // NULL
    cout << endl;

    for (int i = 0; i < 5; i++) {
        Push(q, i);
    }
    Show(q);
    cout << endl;
    Clear(q);
    Show(q); // NULL
    cout << endl;

    cout << Empty(q) << endl; // 1
    Push(q, 1);
    cout << Empty(q) << endl; // 0

    for (int i = 0; i < 5; i++) {
        Push(q, i);
    }
    cout << Size(q) << endl; // 6
    Clear(q);
    cout << Size(q) << endl; // 0

    TQueue another_queue;
    Create(another_queue);
    for (int i = 0; i < 5; i++) {
        Push(another_queue, i);
    } // Remember that q is empty...
    Swap(q, another_queue);
    Show(q); // 0 -> 1 -> 2 -> 3 -> 4 -> NULL
    cout << endl;
    Show(another_queue); // NULL
    cout << endl;

    cout << Front(q) << endl; // 0
    cout << Back(q); // 4

    return 0;
}
