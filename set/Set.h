//
// Created by antonioalanxs.
//

#ifndef SET_SET_H
#define SET_SET_H

#define LENGHT 100 // The one you want.

// The main characteristic of a set is that its search algorithm has complexity O(1), and that is why they are used. In
// this case, we are going to implement it as a boolean vector which will have integers as indexes but really these
// indexes can be anything (an object, a string, etc.) thanks to hash functions (e.g.: Java HashSet).
//
// Another characteristic of sets is that there cannot be repeated elements.

typedef struct TSet {
    bool values [LENGHT];
    int size;
} TSet;

// Generation constructors:
void Create(TSet &s);

// Modification constructors:
void PushFront(TSet &s, int value);
void Remove(TSet &s, int value);

// Selective observers:

// Non-selective observers:
bool Empty(TSet s);
bool Find(TSet s, int target);
int Size(TSet s);

#endif
