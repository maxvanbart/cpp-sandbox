#ifndef SANDBOX_TENSOR_H
#define SANDBOX_TENSOR_H

class Tensor {
public:
    Tensor();
    Tensor(int d1, int d2, int d3);
    ~Tensor();
    double& operator[] (int i) const;
    double& operator() (int i, int j, int k) const;


    int height;
    int width;
    int depth;
    int size;
    double* data;
};

#endif
