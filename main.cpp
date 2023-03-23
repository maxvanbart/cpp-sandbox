#include <iostream>
#include "FTensor.hpp"

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

    FTensor::Tensor2<double, 3, 3> weight;
    FTensor::Tensor1<double, 3> x;
    FTensor::Tensor1<double, 3> bias;
    auto y = x * weight + bias;

    return 0;
}
// comment line