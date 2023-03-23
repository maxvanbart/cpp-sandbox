#include <iostream>

#include "tensor.h"
#include "convolute.h"
#include "MaxPool.h"

int fibonacci(int n) {
    if (n == 1) {
        return 1;
    } else if (n < 1) {
        return 0;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


int main() {
    std::cout << "Hello world!\n";
    int i = 4;

    std::cout << i << "th fibonacci number: " << fibonacci(i) << "\n";

//    Tensor t1(3, 3, 3);

    Tensor t1(9, 9, 1);

    t1[4] = 55;
    t1(1,1,0) = 4;
    t1(1,2,0) = 8;
    t1(4,4,0) = 9;
    t1(8,8,0) = 10;
    t1[4] += 2;

    t1.print();
    Tensor t2 = maxpool(t1, 3, 3);
    t2.print();

    Conv2d l1(3, 5, 3, 1, 0);
    l1.init_params();
    l1.print();


    return 0;
}
// comment line