#include <iostream>

#include "tensor.h"

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

    Tensor t1(3, 3, 3);

    t1[4] = 55;

    std::cout << t1(1,1,0) << std::endl;

    return 0;
}
// comment line