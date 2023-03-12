//
// Created by maxva on 12-3-2023.
//

#include "cat.h"

// Function for a simple cat class

int Cat::getAge() const {
    return age_;
}

Cat::Cat() {
    age_ = 5;
}

Cat::Cat(int age) {
    age_ = age;
}