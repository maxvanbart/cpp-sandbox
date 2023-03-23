//
// Created by jen on 23/03/2023.
//

#include "MaxPool.h"



Tensor maxpool(const Tensor& x, int KS, int stride) {
    int w_out_max = floor(1 + (x.width - KS)/stride);
    int h_out_max = floor(1 + (x.height - KS)/stride);
    Tensor y = Tensor(w_out_max, h_out_max, x.depth);

    for (int k = 0; k < x.depth; k++) {
        for (int I = 0; I < floor(w_out_max/KS); I++) {
            for (int J = 0; J < floor(h_out_max/KS); J++) {
                double max_val = 0;
                for (int i = 0; i < KS; i++) {
                    for (int j = 0; j < KS; j++) {
//                        double i_max = std::max(x(i,j,k),x(i+1,j,k));
//                        double j_max = std::max(x(i,j+1,k),xj+1]);
                        max_val = std::max(max_val,x(I*KS+i, J*KS+j, k));
                    }
                }
                y(I,J,k) = max_val;
            }
        }
    }



    return y;
}