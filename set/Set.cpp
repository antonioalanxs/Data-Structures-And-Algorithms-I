//
// Created by antonioalanxs.
//

#include "Set.h"

void Create(TSet &s) {
    s.size = 0;
    for (bool & b : s.values) {
        b = false;
    }
}

void PushFront(TSet &s, int value) {
    if (!(value > LENGHT - 1) && !Find(s, value)) {
        s.values[value] = true;
        s.size++;
    }
}

void Remove(TSet &s, int value) {
    if (!(value > LENGHT - 1) && Find(s, value)) {
        s.values[value] = false;
        s.size--;
    }
}

bool Empty(TSet s) {
    return s.size == 0;
}

bool Find(TSet s, int target) {
    if (!(target > LENGHT - 1)) {
        return s.values[target];
    }
    return false;
}

int Size(TSet s) {
    return s.size;
}