#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;

int main() { // Quick test!
    TStack s;
    Create(s); // s = nullptr;

    Push(s, 1);
    cout << Peek(s) << endl; // 1

    Push(s, 2);
    cout << Peek(s) << endl; // 2
    Push(s, 3);
    cout << Peek(s) << endl; // 3

    Pop(s);
    cout << Peek(s) << endl; // 2
    Pop(s);
    cout << Peek(s) << endl; // 1

    cout << Empty(s) << endl; // 0
    Pop(s);
    cout << Empty(s) << endl; // 1
    Pop(s);
    for (int i = 0; i < 5; i++) {
        Push(s, i);
    }
    Clear(s);
    cout << Empty(s) << endl; // 1

    cout << Peek(s) << endl; // -1

    cout << Size(s) << endl; // 0
    for (int i = 0; i < 5; i++) {
        Push(s, i);
    }
    cout << Size(s); // 5

    return 0;
}
