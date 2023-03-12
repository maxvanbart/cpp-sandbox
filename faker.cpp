
#include "faker.h"
#include "cat.h"

#include<iostream>

int faker(int n) {
    // Faker function to interface C and C++

    std::cout << "Hello world from C++!\n";

    Cat poes;
    Cat kat(11);


    std::cout << "Poes age: " << poes.getAge() << std::endl;
    std::cout << "Kat age: " << kat.getAge() << std::endl;

    return 2 * n * n;
}

int *cumsum(int data[]) {
    // A cumsum which aims to demonstrate the ability to parse arrays
    std::cout << "Data:" << std::endl;

    // For some reason parsing might not work if arrays aren't static
    static int r[4];
    int k = 0;
    for (int i = 0; i < 4; i++) {
        std::cout << data[i] << std::endl;

        k += data[i];
        r[i] = k;
    }



    return r;
}