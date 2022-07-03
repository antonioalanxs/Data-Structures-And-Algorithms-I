//
// Created by antonioalanxs.
//

#include <iostream>
#include "Queue.h"

using std::cout;

void Create(TQueue &q) {
    q.head_ptr = nullptr;
    q.last_ptr = nullptr;
}

void Push(TQueue &q, int value) {
    TNode* new_node_ptr = new TNode;
    new_node_ptr->value = value;
    new_node_ptr->next = nullptr;
    if (q.head_ptr == nullptr) { // == last_ptr (It is an empty queue).
        q.head_ptr = new_node_ptr;
    }
    if (q.last_ptr != nullptr) { // It is not an empty queue. We can change this sentence to an "else" sentence but
                                 // this is more descriptive than it.
        q.last_ptr->next = new_node_ptr;
    }
    q.last_ptr = new_node_ptr; // We update the queue's last node.
}

void Pop(TQueue &q) {
    if (q.head_ptr != nullptr) {
        TNode* aux_ptr = q.head_ptr;
        if (q.head_ptr == q.last_ptr) { // One node queue case. It avoids the error that the last pointer points to a
                                        // random memory address because of deleting the memory address it was pointing
                                        // to and later to a form of the SIGTRAP error.
            q.head_ptr = nullptr;
            q.last_ptr = nullptr;
        } else {
            q.head_ptr = q.head_ptr->next;
        }
        delete aux_ptr;
    }
}

void Clear(TQueue &q) {
    while (q.head_ptr != nullptr) {
        Pop(q);
    }
}

void Swap(TQueue &q, TQueue &another_q) {
    if (!(Empty(q) && Empty(another_q))) {
        TQueue aux_q_ptr = q;
        q = another_q;
        another_q = aux_q_ptr;
    }
}

int Front(TQueue q) {
    if (q.head_ptr != nullptr) {
        return q.head_ptr->value;
    }
    return -1;
}

int Back(TQueue q) {
    if (q.last_ptr != nullptr) {
        return q.last_ptr->value;
    }
    return -1;
}

bool Empty(TQueue q) {
    return q.head_ptr == nullptr;
}

bool LinearSearch(TQueue q, int target) {
    bool is_found = false;
    while (!is_found && q.head_ptr != nullptr) {
        is_found = q.head_ptr->value == target;
        if (!is_found) {
            q.head_ptr = q.head_ptr->next;
        }
    }
    return is_found;
}

int Size(TQueue q) {
    int counter = 0;
    while (q.head_ptr != nullptr) {
        counter++;
        q.head_ptr = q.head_ptr->next;
    }
    return counter;
}

void Show(TQueue q) {
    while (q.head_ptr != nullptr) {
        cout << q.head_ptr->value << " -> ";
        q.head_ptr = q.head_ptr->next;
    }
    cout << "NULL";
}
