#include "base.h"
#include <iostream>
#include <stdio.h>

__global__ void print_one()
{
    printf("1\n");
}

void hello()
{
    std::cout << "Hello World from GPU!\n";
    print_one<<<1, 2>>>();
}