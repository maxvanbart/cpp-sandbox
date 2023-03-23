//
// Created by max on 22-3-23.
//

#ifndef SANDBOX_TENSOR_H
#define SANDBOX_TENSOR_H

template<typename T>
class Tensor {
public:
    explicit Tensor(int d1 = 1, int d2 = 1, int d3 = 1);
    ~Tensor();
    T& operator[] (int i) const;
    T& operator() (int i, int j, int k) const;


private:
    int height;
    int width;
    int depth;
    int size;
    T* data;
};

#endif //SANDBOX_TENSOR_H
