//
// Created by antonioalanxs.
//

#include "Stack.h"

void Create(TStack &s) {
    s.head_ptr = nullptr;
    s.size = 0;
}

void Push(TStack &s, int value) {
    TNode* new_node_ptr = new TNode;
    new_node_ptr->value = value;
    new_node_ptr->next = s.head_ptr;
    s.head_ptr = new_node_ptr;
    s.size++;
}

void Pop(TStack &s) {
    if (s.head_ptr != nullptr) {
        TNode* aux_ptr = s.head_ptr;
        s.head_ptr = s.head_ptr->next;
        delete aux_ptr;
        s.size--;
    }
}

void Clear(TStack &s) {
    while (s.head_ptr != nullptr) {
        Pop(s);
    }
}

int Peek(TStack s) {
    if (s.head_ptr != nullptr) {
        return s.head_ptr->value;
    }
    return -1;
}

bool Empty(TStack s) {
    return s.head_ptr == nullptr; // Or s.size == 0;
}

int Size(TStack s) {
    return s.size;
}
