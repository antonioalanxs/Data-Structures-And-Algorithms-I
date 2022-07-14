#include <iostream>
#include "Set.h"

using std::cout;
using std::endl;

int main() {
    TSet s;
    Create(s);

    PushFront(s, 3);
    PushFront(s, -99);
    PushFront(s, 101);
    PushFront(s, 50);
    cout << Find(s, 3) << endl; // 1
    cout << Find(s, -99) << endl; // 0
    cout << Find(s, 101) << endl; // 0
    cout << Find(s, 50) << endl; // 1

    Remove(s, 3);
    Remove(s, -99);
    cout << Find(s, 3) << endl; // 0
    cout << Find(s, -99) << endl; // 0

    cout << Empty(s) << endl; // 0

    cout << Size(s); // 1

    return 0;
}
