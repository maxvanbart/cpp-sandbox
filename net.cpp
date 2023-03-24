//
// Created by max on 24-3-23.
//

#include "net.h"

Tensor net(Tensor img) {

    Tensor x = img;
    Conv2d l1(3, 32, 3, 1, 1);
    Conv2d l2(32, 64, 3, 1, 1);
    Conv2d l3(64, 128, 3, 1, 1);
    Conv2d l4(128, 64, 1, 1, 0);
    Conv2d l5(64, 128, 3, 1, 1);
    Conv2d l6(128, 256, 3, 1, 1);
    Conv2d l7(256, 128, 1, 1, 0);
    Conv2d l8(128, 256, 3, 1, 1);
    Conv2d l9(256, 512, 3, 1, 1);
    Conv2d l10(512, 256, 1, 1, 0);
    Conv2d l11(256, 512, 3, 1, 1);
    Conv2d l12(512, 256, 1, 1, 0);
    Conv2d l13(256, 512, 3, 1, 1);
    Conv2d l14(512, 1024, 3, 1, 1);
    Conv2d l15(1024, 512, 1, 1, 0);
    Conv2d l16(512, 1024, 3, 1, 1);
    Conv2d l17(1024, 512, 1, 1, 0);
    Conv2d l18(512, 1024, 3, 1, 1);

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

    return x;
}