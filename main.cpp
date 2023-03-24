#include <iostream>

#include "tensor.h"
#include "convolute.h"
#include "MaxPool.h"
#include "relu.h"
#include "linear.h"
#include "net.h"

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

    Tensor t1(9, 9, 3);

    t1[4] = 55;
    t1(1,1,0) = 4;
    t1(1,2,0) = 8;
    t1(4,4,0) = 9;
    t1(8,8,0) = 10;
    t1[4] += 2;

    t1(5,2,2) = 44;
    t1(3,5,1) = 22;
    t1(3,4,2) = 11;
    t1(8,5,1) = 33;

//    t1.print();
    Tensor t2 = maxpool(t1, 3, 3);
//    t2.print();

    Conv2d l1(3, 3, 3, 2, 1);
    l1.init_params();
    l1.print();

    std::cout << "Testing convolution" << std::endl;
    t1.print();
    Tensor t3 = l1.forward(t1);
    t3.print();
    Tensor t4 = relu(t3);
    t4.print();
    Tensor t5 = t4.flatten();
    t5.print();

    Tensor t6(5,1,1);
    t6[0] = 2;
    t6[1] = 2;
    t6[2] = 2;
    t6[3] = 2;
    t6[4] = 2;
    std::cout << "Testing Linear:\n";
    t6.print();
    Linear l2(5, 3);
    l2.init_params();
    Tensor t7 = l2.forward(t6);
    t7.print();

    Tensor t8(448, 448, 3);
    std::cout << t8.width << " " << t8.height << " " << t8.depth << std::endl;
    Tensor t9 = net(t8);
    std::cout << t9.width << " " << t9.height << " " << t9.depth << std::endl;

    return 0;
}
// comment line