#include "tensor.h"

//template<typename T>
//class Tensor<T>::Tensor {
//public:
//    explicit Tensor(int d1 = 1, int d2 = 1, int d3 = 1) {
//        width = d1;
//        height = d2;
//        depth = d3;
//        size = width * height * depth;
//        data = new T[size];
//    }
//
//    ~Tensor() {
//        delete[] data;
//        size = 0;
//    }
//
//    T& operator[] (int i) const {
//        if (i < size) {
//            return data[i];
//        }
//    }
//
//    T& operator() (int i, int j, int k) const {
//        int entry = i + width * j + width * height * k;
//        if (entry < size) {
//            return data[entry];
//        } else {
//            return 0;
//        }
//    }
//
////private:
////    T* data;
////    int width;
////    int height;
////    int depth;
////    int size;
//};

Tensor::Tensor() {
    width = 0;
    height = 0;
    depth = 0;
    size = 0;
    data = nullptr;
}

Tensor::Tensor(int d1, int d2, int d3) {
    width = d1;
    height = d2;
    depth = d3;
    size = width * height * depth;
    data = new double[size];
}

Tensor::~Tensor() {
    delete[] data;
    size = 0;
}

double &Tensor::operator[](int i) const {
    if (i < size) {
        return data[i];
    }
}

double &Tensor::operator()(int i, int j, int k) const {
    int entry = i + width * j + width * height * k;
    if (entry < size) {
        return data[entry];
    } else {
        return data[0];
    }
}
