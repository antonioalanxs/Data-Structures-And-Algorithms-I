//
// Created by antonioalanxs.
//

#include <iostream>
#include "SinglyLinkedList.h"

using std::cout;
using std::endl;

// We use "nullptr" since "NULL" indicates 0.
void Create(TList &head_ptr) {
    head_ptr = nullptr;
}

void PushFront(TList &head_ptr, int value) {
    TNode* new_node_ptr = new TNode;
    new_node_ptr->value = value;
    new_node_ptr->next = head_ptr; // We insert it from the left.
    head_ptr = new_node_ptr; // We reposition the header.
}

void PushBack(TList &head_ptr, int value) {
    TNode* new_node_ptr = new TNode;
    new_node_ptr->value = value;
    new_node_ptr->next = nullptr;
    if (head_ptr == nullptr) {
        head_ptr = new_node_ptr;
    } else {
        TList aux_ptr = head_ptr; // We define an auxiliary pointer so as not to lose the reference to the header.
        while (aux_ptr->next != nullptr) { // We traverse the list until we reach the last node.
            aux_ptr = aux_ptr->next;
        }
        aux_ptr->next = new_node_ptr; // We bind the node last.
    }
}

void PopFront(TList &head_ptr) {
    if (head_ptr != nullptr) {
        TList aux_ptr = head_ptr;
        head_ptr = head_ptr->next;
        delete aux_ptr;
//        aux_ptr = nullptr; // It really isn't necessary.
    }
}

void PopBack(TList &head_ptr) {
    if (head_ptr != nullptr) {
        if (head_ptr->next == nullptr) { // The list only has one node (its header).
            delete head_ptr;
        } else {
            TList aux_prev_ptr = head_ptr;
            TList aux_post_ptr = aux_prev_ptr->next;
            while (aux_post_ptr->next != nullptr) {
                aux_post_ptr = aux_post_ptr->next;
                aux_prev_ptr = aux_prev_ptr->next;
            }
            aux_prev_ptr->next = nullptr; // So that its "next" field doesn't point to a random memory address after
                                          // deleting to the memory address it originally pointed to.
            delete aux_post_ptr;
        }
    }
}

void Remove(TList &head_ptr, int value) {
    if (head_ptr != nullptr) {
        TList aux_prev_ptr = head_ptr;
        TList aux_post_ptr = aux_prev_ptr->next;
        if (head_ptr->value == value) { // The target is in the first position.
            head_ptr = head_ptr->next;
            delete aux_prev_ptr;
        } else { // The target is in an intermediate position or in the last position.
            bool is_found = false;
            while (!is_found && aux_post_ptr != nullptr) { // We haven't set its "next" field to count the last node
                                                           // (which has its "next" field set to nullptr).
                is_found = aux_post_ptr->value == value;
                if (!is_found) {
                    aux_post_ptr = aux_post_ptr->next;
                    aux_prev_ptr = aux_prev_ptr->next;
                }
            }
            if (is_found) { // If it has found it, it will delete it. Otherwise, it will do nothing.
                if (aux_post_ptr->next != nullptr) { // Intermediate position.
                    aux_prev_ptr->next = aux_post_ptr->next; // We link the previous node with the posterior node.
                    delete aux_post_ptr; // We remove the target node, which is the intermediate one.
                } else { // Last position.
                    aux_prev_ptr->next = nullptr;
                    delete aux_post_ptr;
                }
            }
        }
    }
}

void Clear(TList &head_ptr) {
    while (head_ptr != nullptr) {
        PopFront(head_ptr);
    }
}

int Front(TList head_ptr) {
    if (head_ptr != nullptr) {
        return head_ptr->value;
    }
    return -1;
}

int Back(TList head_ptr) {
    if (head_ptr != nullptr) {
        while (head_ptr->next != nullptr) {
            head_ptr = head_ptr->next;
        }
        return head_ptr->value;
    }
    return -1;
}

bool Empty(TList head_ptr) {
    return head_ptr == nullptr;
}

bool LinearSearch(TList head_ptr, int target) {
    bool is_found = false;
    while (head_ptr != nullptr && !is_found) {
        is_found = head_ptr->value == target;
        if (!is_found) {
            head_ptr = head_ptr->next;
        }
    }
    return is_found;
}

int Size(TList head_ptr) {
    int counter = 0;
    while (head_ptr != nullptr) {
        counter++;
        head_ptr = head_ptr->next;
    }
    return counter;
}

void Show(TList head_ptr) {
    while (head_ptr != nullptr) {
        cout << head_ptr->value << " -> ";
        head_ptr = head_ptr->next;
    }
    cout << "NULL";
}
