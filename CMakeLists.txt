cmake_minimum_required(VERSION 3.24)
project(sandbox)

set(CMAKE_CXX_STANDARD 17)

add_executable(sandbox main.c faker.cpp cat.cpp cat.h tensor.cpp tensor.h MaxPool.cpp MaxPool.h padding.cpp padding.h convolute.cpp convolute.h relu.cpp relu.h linear.cpp linear.h net.cpp net.h)
