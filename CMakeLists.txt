cmake_minimum_required(VERSION 3.24)
project(sandbox)

set(CMAKE_CXX_STANDARD 17)

add_executable(sandbox main.cpp faker.cpp cat.cpp cat.h tensor.cpp tensor.h MaxPool.cpp MaxPool.h padding.cpp padding.h)
