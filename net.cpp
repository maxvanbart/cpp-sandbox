//
// Created by max on 24-3-23.
//

#include "net.h"

Tensor net(Tensor img) {

    int time_before_loop_begins = time(NULL);

    Tensor x = img;
    Conv2d l1(3, 16, 3, 1, 1);
    Conv2d l2(16, 32, 3, 1, 1);
    Conv2d l3(32, 64, 3, 1, 1);
    Conv2d l4(64, 32, 1, 1, 0);
    Conv2d l5(32, 64, 3, 1, 1);
    Conv2d l6(64, 128, 3, 1, 1);
    Conv2d l7(128, 64, 1, 1, 0);
    Conv2d l8(64, 128, 3, 1, 1);
    Conv2d l9(128, 256, 3, 1, 1);
    Conv2d l10(256, 128, 1, 1, 0);
    Conv2d l11(128, 256, 3, 1, 1);
    Conv2d l12(256, 128, 1, 1, 0);
    Conv2d l13(128, 256, 3, 1, 1);
    Conv2d l14(256, 512, 3, 1, 1);
    Conv2d l15(512, 256, 1, 1, 0);
    Conv2d l16(256, 512, 3, 1, 1);
    Conv2d l17(512, 256, 1, 1, 0);
    Conv2d l18(256, 512, 3, 1, 1);

    // downsize 448 * 448 input
    x = maxpool(x, 2, 2);
    x = l1.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l2.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l3.forward(x);
    x = relu(x);
    x = l4.forward(x);
    x = relu(x);
    x = l5.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l6.forward(x);
    x = relu(x);
    x = l7.forward(x);
    x = relu(x);
    x = l8.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l9.forward(x);
    x = relu(x);
    x = l10.forward(x);
    x = relu(x);
    x = l11.forward(x);
    x = relu(x);
    x = l12.forward(x);
    x = relu(x);
    x = l13.forward(x);
    x = relu(x);
    x = maxpool(x, 2, 2);
    x = l14.forward(x);
    x = relu(x);
    x = l15.forward(x);
    x = relu(x);
    x = l16.forward(x);
    x = relu(x);
    x = l17.forward(x);
    x = relu(x);
    x = l18.forward(x);
    x = relu(x);

    int time_after_loop_ends = time(NULL);
    int time_diff = time_after_loop_ends - time_before_loop_begins;

    std::cout << "Time taken for forward pass: "<< time_diff << " seconds." << std::endl;

    return x;
}