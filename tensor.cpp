//
// Created by max on 22-3-23.
//

#include "tensor.h"

template<typename T>
class Tensor {
public:
    explicit Tensor(int d1 = 1, int d2 = 1, int d3 = 1) {
        width = d1;
        height = d2;
        depth = d3;
        size = width * height * depth;
        data = new T[size];
    }

    ~Tensor() {
        delete[] data;
        size = 0;
    }

    T& operator[] (int i) const {
        if (i < size) {
            return data[i];
        }
    }

    T& operator() (int i, int j, int k) const {
        int entry = i + width * j + width * height * k;
        if (entry < size) {
            return data[entry];
        } else {
            return 0;
        }
    }

//private:
//    T* data;
//    int width;
//    int height;
//    int depth;
//    int size;
};

explicit Tensor<>::Tensor(int d1 = 1, int d2 = 1, int d3 = 1) {
    width = d1;
    height = d2;
    depth = d3;
    size = width * height * depth;
    data = new T[size];
}


template<typename T>
Tensor<T> pad(Tensor<T> x, int padding) {
    int w_out = x.width + padding * 2;
    int h_out = x.height + padding * 2;
    Tensor<T> y = Tensor<T>(w_out, h_out, x.depth);

    for (int i = 0; i < x.width; i++) {
        for (int j = 0; j < x.height; j++) {
            for (int k = 0; k < x.depth; k++) {
                y(i + padding, j+padding, k) = x(i, j, k);
            }
        }
    }
    return y;
}
