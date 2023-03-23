////
//// Created by jen on 23/03/2023.
////
//
//#include "MaxPool.h"
//
//// Pad the input
//int x_padded = pad(x, [self.padding] * 4)
//
//// Unpack the needed dimensions
//N, C, H, W = x.shape
//KS = self.kernel_size
//
//# Calculate output height and width
//Hp = 1 + (H + 2 * self.padding - KS) // self.stride
//Wp = 1 + (W + 2 * self.padding - KS) // self.stride