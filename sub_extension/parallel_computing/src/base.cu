#include "base.cuh"
#include <iostream>

__global__ void print_one()
{
    printf("1\n");
}

void hello()
{
    std::cout << "Hello World from GPU!\n";
    print_one<<<1, 2>>>();
}