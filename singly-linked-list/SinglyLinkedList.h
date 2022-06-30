//
// Created by antonioalanxs.
//

#ifndef SINGLY_LINKED_LIST_SINGLYLINKEDLIST_H
#define SINGLY_LINKED_LIST_SINGLYLINKEDLIST_H

// The use of "template <typename T>" is not defined on structs.
typedef struct TNode {
    int value;
    TNode* next;
} TNode;

typedef TNode* TList;

// Generation constructors:
void Create(TList &head_ptr);

// Modification constructors:
void PushFront(TList &head_ptr, int value);
void PushBack(TList &head_ptr, int value);
void PopFront(TList &head_ptr);
void PopBack(TList &head_ptr);
void Remove(TList &head_ptr, int value);
void Clear(TList &head_ptr);

// Selective observers:
int Front(TList head_ptr);
int Back(TList head_ptr);

// Non-selective observers:
bool Empty(TList head_ptr);
bool LinearSearch(TList head_ptr, int target);
int Size(TList head_ptr);
void Show(TList head_ptr);

#endif
