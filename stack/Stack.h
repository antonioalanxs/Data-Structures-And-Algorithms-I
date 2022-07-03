//
// Created by antonioalanxs.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef struct TNode {
    int value;
    TNode* next;
} TNode;

typedef struct TStack {
    TNode* head_ptr;
    int size; // We need this property because a stack cannot be traversed (we can only access the top element).
} TStack;

// Generation constructors:
void Create(TStack &s);

// Modification constructors:
void Push(TStack &s, int value);
void Pop(TStack &s);
void Clear(TStack &s);

// Selective observers:
int Peek(TStack s); // Top

// Non-selective observers:
bool Empty(TStack s);
int Size(TStack s);

#endif
