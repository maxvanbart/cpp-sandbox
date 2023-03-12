//
// Created by maxva on 12-3-2023.
//

#include "faker.h"

#include<iostream>

int faker(int n) {
    std::cout << "Hello world from C++!\n";

    return 2 * n * n;
}

int *cumsum(int data[]) {
    std::cout << "Data:" << std::endl;


    static int r[4];
    int k = 0;
    for (int i = 0; i < 4; i++) {
        std::cout << data[i] << std::endl;

        k += data[i];
        r[i] = k;
    }



    return r;
}