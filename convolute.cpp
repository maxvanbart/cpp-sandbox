//
// Created by max on 23-3-23.
//

#include "convolute.h"

Conv2d::Conv2d() {
    in_channels = 0;
    out_channels = 0;
    kernel_size = 0;
    stride = 0;
    padding = 0;
    weight = nullptr;
    bias = nullptr;
}

Conv2d::Conv2d(int in_channels_, int out_channels_, int kernel_size_, int stride_, int padding_) {
    in_channels = in_channels_;
    out_channels = out_channels_;
    kernel_size = kernel_size_;
    stride = stride_;
    padding = padding_;

    weight = new Tensor[out_channels];
    for (int i = 0; i < out_channels; i++) {
        weight[i] = Tensor(kernel_size, kernel_size, in_channels);
    }
    bias = new double[out_channels];
}

Conv2d::~Conv2d() {
    delete[] weight;
    delete[] bias;
}

Tensor Conv2d::forward(const Tensor &x) {
    return x;
}

void Conv2d::init_params() {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, 0.667);

    for (int i = 0; i < out_channels; i++) {
        bias[i] = distribution(generator);
        for (int j = 0; j < weight[i].size; j++) {
            weight[i].data[j] = distribution(generator);
        }
    }
}

void Conv2d::print() {
    std::cout << "Biases: [ ";
    for (int i = 0; i < out_channels; i++) {
        std::cout << bias[i] << " ";
    }
    std::cout << "]\n";
}
