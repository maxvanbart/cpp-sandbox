//
// Created by jen on 24/03/2023.
//

#include "Avgpool.h"

Tensor avgpool(const Tensor& x, int KS, int stride) {
    int w_out_max = floor(1 + (x.width - KS) / stride);
    int h_out_max = floor(1 + (x.height - KS) / stride);
    Tensor y = Tensor(w_out_max, h_out_max, x.depth);

    for (int k = 0; k < x.depth; k++) {
        for (int I = 0; I < w_out_max; I++) {
            for (int J = 0; J < h_out_max; J++) {
                double avg_val = 0;
                for (int i = 0; i < KS; i++) {
                    for (int j = 0; j < KS; j++) {
                        avg_val = x(I * stride + i, J * stride + j, k);
                    }
                }
//                std::cout << "Found maximum value of " << max_val << " for I=" << I << " and J=" << J << std::endl;
                y(I, J, k) = 1.0;
            }
        }
    }
}