//
// Created by jen on 24/03/2023.
//

#ifndef SANDBOX_AVGPOOL_H
#define SANDBOX_AVGPOOL_H

#include"padding.h"

#include<cmath>
#include<iostream>

Tensor maxpool(const Tensor& x, int KS, int stride);

#endif //SANDBOX_AVGPOOL_H
