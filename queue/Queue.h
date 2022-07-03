//
// Created by antonioalanxs.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef struct TNode {
    int value;
    TNode* next;
} TNode;

typedef struct TQueue {
    TNode* head_ptr;
    TNode* last_ptr;
} TQueue;

// Generation constructors:
void Create(TQueue &q);

// Modification constructors:
void Push(TQueue &q, int value);
void Pop(TQueue &q);
void Clear(TQueue &q);
void Swap(TQueue &q, TQueue &another_q);

// Selective observers:
int Front(TQueue q);
int Back(TQueue q);

// Non-selective observers:
bool Empty(TQueue q);
bool LinearSearch(TQueue q, int target);
int Size(TQueue q);
void Show(TQueue q);

#endif
