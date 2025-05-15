// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdlib>

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
    if (!first) return;

    Car* current = first->next;
    while (current != first) {
        Car* temp = current;
        current = current->next;
        delete temp;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};

    if (!first) {
        first = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    Car* current = first;

    while (true) {
        if (!current->light) {
            current->light = true;
            countOp++;
            current = current->next;
        } else {
            current->light = false;
            int count = 1;
            countOp++;
            Car* temp = current->next;

            while (true) {
                countOp++;
                if (temp->light) break;
                temp = temp->next;
                count++;
            }

            if (temp == current) return count;
            else {
                current = temp;
            }
        }
    }
}

int Train::getOpCount() {
    return countOp;
}

void Train::resetOpCount() {
    countOp = 0;
}
